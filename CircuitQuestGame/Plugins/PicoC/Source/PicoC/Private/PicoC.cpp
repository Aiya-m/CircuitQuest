// Copyright Epic Games, Inc. All Rights Reserved.

#include "PicoC.h"
#include "Misc/MessageDialog.h"
#include "Modules/ModuleManager.h"
#include "Misc/Paths.h"
#include "HAL/PlatformProcess.h"

extern "C" 
{
	#include "PicoCLibrary/picoc.h"
	#include "PicoCLibrary/interpreter.h"
	#include "setjmp.h"
}

FOneFunctionDelegate FPicoCModule::OnDelay;
FTwoFunctionDelegate FPicoCModule::OnDigitalWrite;
static Picoc PCState;

#define LOCTEXT_NAMESPACE "FPicoCModule"

// Macro Template for function 1 args
#define MAKE_BRIDGE_1ARGS(BridgeName, DelegateName) \
void BridgeName(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) \
{ \
	if (NumArgs < 1 || !Param || !Param[0] || !Param[0]->Val) \
	{ \
		UE_LOG(LogTemp, Error, TEXT("Arduino Bridge -> %s: Missing argument!"), TEXT(#DelegateName)); \
		return; \
	} \
	\
	int32 Arg1 = Param[0]->Val->Integer; \
	UE_LOG(LogTemp, Warning, TEXT("Arduino Bridge -> %s : %d"), TEXT(#DelegateName), Arg1); \
	\
	if (!FPicoCModule::DelegateName.IsBound()) \
	{ \
		UE_LOG(LogTemp, Error, TEXT("Arduino Bridge -> %s: is not bound!"), TEXT(#DelegateName)); \
		return; \
	} \
	FPicoCModule::DelegateName.ExecuteIfBound(Arg1); \
}

// Macro Template for function 2 args
#define MAKE_BRIDGE_2ARGS(BridgeName, DelegateName) \
void BridgeName(struct ParseState *Parser, struct Value *ReturnValue, struct Value **Param, int NumArgs) \
{ \
	int32 Arg1 = Param[0]->Val->Integer; \
	int32 Arg2 = Param[1]->Val->Integer; \
	UE_LOG(LogTemp, Warning, TEXT("Arduino Bridge -> %s : %d, %d"), TEXT(#DelegateName), Arg1, Arg2); \
	\
	if (!FPicoCModule::DelegateName.IsBound()) \
	{ \
	UE_LOG(LogTemp, Error, TEXT("Arduino Bridge -> %s: is not bound!"), TEXT(#DelegateName)); \
	return; \
	} \
	FPicoCModule::DelegateName.ExecuteIfBound(Arg1, Arg2); \
}

MAKE_BRIDGE_1ARGS(Bridge_delay, OnDelay);
MAKE_BRIDGE_2ARGS(Bridge_digitalWrite, OnDigitalWrite);

#pragma warning(push)
#pragma warning(disable: 4611)
// only c language in here
extern "C" static bool ParsePicoCHeader_Safe(Picoc* pc, const char* HeaderName, const char* SourceCode)
{
	if (setjmp(pc->PicocExitBuf) != 0)
	{
		return false;
	}

	PicocParse(
		pc, 
		HeaderName, 
		SourceCode, 
		strlen(SourceCode), 
		TRUE, 
		FALSE, 
		FALSE, 
		TRUE
	);

	return true;
}
#pragma warning(pop)

void FPicoCModule::StartupModule()
{
 	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	UE_LOG(LogTemp, Warning, TEXT("PicoC Module Started Successfully!"));
	
	// setvbuf(stdout, NULL, _IONBF, 0);
	// setvbuf(stderr, NULL, _IONBF, 0);
	
	PicocInitialise(&PCState, 512000);
	UE_LOG(LogTemp, Warning, TEXT("PCState: %p"), &PCState);
	
 	// Register Bridge Function to PicoC's table
	static LibraryFunction ArduinoFuncLib[] =
	{
		{Bridge_delay, "void delay(int);"},
		{ Bridge_digitalWrite, "void digitalWrite(int, int);" },
		{ NULL, NULL }
	};
	// IncludeRegister(PCState, "ArduinoFuncLib", )
	
	LibraryAdd(&PCState, &PCState.GlobalTable, "ArduinoFuncLib", ArduinoFuncLib);
	UE_LOG(LogTemp, Warning, TEXT("Library registered"));
 	// define constant value
	const char* ArduinoHeader = 
		"#define LOW 0\n"
		"#define HIGH 1\n"
		"#define INPUT 0\n"
		"#define OUTPUT 1\n"
		"#define INPUT_PULLUP 2\n";
	
	bool bSuccess = ParsePicoCHeader_Safe(&PCState, "Arduino_Definitions", ArduinoHeader);
	if (bSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("Arduino Constants Defined Successfully!"));
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to parse Arduino Constants!"));
	}
	
	// Test PicoC Lib
	// struct Picoc_Struct pc;
	// FMemory::Memzero(&pc, sizeof(struct Picoc_Struct)); 
	//
	// PicocInitialise(&pc, 512000); 
	// PicocCleanup(&pc);

	UE_LOG(LogTemp, Warning, TEXT("PicoC with Platform Linked Successfully!"));
}

void FPicoCModule::Compile(const FString& Code)
{
	UE_LOG(LogTemp, Warning, TEXT("Picoc Module (Compile): in Compile function"));
	// FTCHARToUTF8 UTF8(*Code);
	
	FTCHARToUTF8 ConvertedCode(*Code);
	const char* TestCode = ConvertedCode.Get();
	
	// setvbuf(stdout, NULL, _IONBF, 0);

	PicocParse(
		&PCState,
		"Test",
		TestCode,
		strlen(TestCode),
		true,
		true,
		false,
		true);
	UE_LOG(LogTemp, Warning, TEXT("Picoc Module (Compile): Compile completed"));
}

void FPicoCModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	PicocCleanup(&PCState);

	UE_LOG(LogTemp, Warning, TEXT("PicoC Module Shutdown Successfully!"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPicoCModule, PicoC)
