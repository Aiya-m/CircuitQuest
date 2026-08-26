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
static Picoc PCState;
static bool bIsPicoCInitialized;

FOneFunctionDelegate FPicoCModule::OnDelay;
FOneFunctionDelegate FPicoCModule::OnDigitalRead;
FTwoFunctionDelegate FPicoCModule::OnDigitalWrite;
FTwoFunctionDelegate FPicoCModule::OnPinMode;
bool FPicoCModule::bIsRunning = false;

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
	if (FCString::Strcmp(TEXT(#DelegateName), TEXT("OnDelay")) == 0) \
	{ \
		FPlatformProcess::Sleep(Arg1 / 1000.0f); \
	} else { \
		FPicoCModule::DelegateName.ExecuteIfBound(Arg1); \
	} \
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
MAKE_BRIDGE_1ARGS(Bridge_digitalRead, OnDigitalRead);
MAKE_BRIDGE_2ARGS(Bridge_digitalWrite, OnDigitalWrite);
MAKE_BRIDGE_2ARGS(Bridge_pinMode, OnPinMode);

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
		false
	);

	return true;
}
#pragma warning(pop)

static void InitPicoCEnvironment()
{
	if (bIsPicoCInitialized)
	{
		PicocCleanup(&PCState);
		bIsPicoCInitialized = false;
	}

	PicocInitialise(&PCState, 512000);
	bIsPicoCInitialized = true;
	UE_LOG(LogTemp, Warning, TEXT("PCState: %p"), &PCState);

	static LibraryFunction ArduinoFuncLib[] =
	{
		{Bridge_delay, "void delay(int);" },
		{Bridge_digitalWrite, "void digitalWrite(int, int);" },
		{Bridge_pinMode, "void pinMode(int, int);" },
		{Bridge_digitalRead, "bool digitalRead(int);" },
		{NULL, NULL }
	};
	LibraryAdd(&PCState, &PCState.GlobalTable, "ArduinoFuncLib", ArduinoFuncLib);

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
}

void FPicoCModule::StartupModule()
{
 	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	UE_LOG(LogTemp, Warning, TEXT("PicoC Module Started Successfully!"));
	InitPicoCEnvironment();
	
	// Test PicoC Lib
	// struct Picoc_Struct pc;
	// FMemory::Memzero(&pc, sizeof(struct Picoc_Struct)); 
	//
	// PicocInitialise(&pc, 512000); 
	// PicocCleanup(&pc);

	UE_LOG(LogTemp, Warning, TEXT("PicoC with Platform Linked Successfully!"));
}

bool IsHasFunction(Picoc* pc, const char* FunctionName)
{
	struct Value* FuncVal = NULL;
	return TableGet(&pc->GlobalTable, TableStrRegister(pc, FunctionName), &FuncVal, NULL, NULL, NULL) != 0;
}

void FPicoCModule::Compile(const FString& Code)
{
	AsyncTask(ENamedThreads::AnyBackgroundThreadNormalTask, [this, Code]()
	{
		UE_LOG(LogTemp, Warning, TEXT("Picoc Module (Compile): in Compile function"));
		InitPicoCEnvironment();
		bIsRunning = false;
		// FTCHARToUTF8 UTF8(*Code);
		
		FTCHARToUTF8 ConvertedCode(*Code);
		const char* TestCode = ConvertedCode.Get();
		
		// bool bHasSetup = Code.Contains(TEXT("void setup"));
		// UE_LOG(LogTemp, Warning, TEXT("%hhd"), bHasSetup);
		
		
		if (!ParsePicoCHeader_Safe(&PCState, "UserCode", TestCode))
		{
			UE_LOG(LogTemp, Error, TEXT("PicoC Compile Error!"));
			return;
		}
		
		const char* runSetup = "setup();";
		if (IsHasFunction(&PCState, "setup"))
		{
			if (!ParsePicoCHeader_Safe(&PCState, "setup", runSetup))
			{
				UE_LOG(LogTemp, Error, TEXT("PicoC setup() Execution Error!"));
				return;
			}
		} else
		{
			UE_LOG(LogTemp, Error, TEXT("No setup() Function!"));
		}
			
		bIsRunning = true;
		UE_LOG(LogTemp, Warning, TEXT("Picoc Module (Compile): Compile completed"));
	});
}

bool FPicoCModule::IsRunning() const
{
	return bIsRunning;
}

void FPicoCModule::RunLoop()
{
	if (!bIsRunning || !bIsPicoCInitialized)
	{
		return;
	}
	
	const char* runLoop = "loop();";
	if (IsHasFunction(&PCState, "loop"))
	{
		if (!ParsePicoCHeader_Safe(&PCState, "loop", runLoop))
        	{
        		UE_LOG(LogTemp, Error, TEXT("PicoC Runtime Error inside loop()! Stopping."));
        		Stop();
        	}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("No loop() Function! Stopping."));
		Stop();
	}
	
}

void FPicoCModule::Stop()
{
	bIsRunning = false;
	UE_LOG(LogTemp, Warning, TEXT("PicoC: Execution stopped."));
}

void FPicoCModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	if (bIsPicoCInitialized)
	{
		PicocCleanup(&PCState);
		bIsPicoCInitialized = false;
	}

	UE_LOG(LogTemp, Warning, TEXT("PicoC Module Shutdown Successfully!"));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FPicoCModule, PicoC)
