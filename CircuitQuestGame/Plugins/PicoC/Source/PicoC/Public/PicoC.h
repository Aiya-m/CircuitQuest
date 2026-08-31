// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

typedef void (*PicoCFuncPtr)(struct ParseState *Parser, struct Value *ReTurnValue, struct Value **Param, int NumParam);

DECLARE_DELEGATE_OneParam(FOneFunctionDelegate, int32);
DECLARE_DELEGATE_TwoParams(FTwoFunctionDelegate, int32, int32);

class PICOC_API FPicoCModule : public IModuleInterface
{
public:
	static inline FPicoCModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FPicoCModule>("PicoC");
	}

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	bool IsRunning() const;
	
	void Compile(const FString& Code);
	void RunLoop();
	void Stop();
	
	// for delegate method
	static FOneFunctionDelegate OnDelay;
	static FOneFunctionDelegate OnDigitalRead;
	static FTwoFunctionDelegate OnDigitalWrite;
	static FTwoFunctionDelegate OnPinMode;
	

private:
	/** Handle to the test dll we will load */
	static bool bIsRunning;
};
