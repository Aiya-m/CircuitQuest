// Fill out your copyright notice in the Description page of Project Settings.


#include "WBP_IDE.h"
#include "PicoC.h"
#include "TaskSyncManager.h"

void UWBP_IDE::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	Super::NativeTick(MyGeometry, InDeltaTime);

	// static float AccumulatedTime = 0.0f;
	// AccumulatedTime += InDeltaTime;
	//
	// if (AccumulatedTime >= 0.05f)
	// {
	// 	AccumulatedTime = 0.0f;
	//
	// 	FPicoCModule& PicoCModule = FModuleManager::GetModuleChecked<FPicoCModule>("PicoC");
	// 	if (PicoCModule.IsRunning())
	// 	{
	// 		PicoCModule.RunLoop();
	// 	}
	// }
	
	FPicoCModule& PicoCModule = FModuleManager::GetModuleChecked<FPicoCModule>("PicoC");
	if (PicoCModule.IsRunning())
	{
		PicoCModule.RunLoop();
	}
}
void UWBP_IDE::NativeConstruct()
{
	Super::NativeConstruct();
	
	// ResetCodeTemplate();
	
	FPicoCModule::OnDelay.BindUObject(this, &UWBP_IDE::DelayFunction);
	FPicoCModule::OnDigitalRead.BindUObject(this, &UWBP_IDE::DigitalReadFuction);
	FPicoCModule::OnDigitalWrite.BindUObject(this, &UWBP_IDE::DigitalWriteFunction);
	FPicoCModule::OnPinMode.BindUObject(this, &UWBP_IDE::PinModeFunction);
}

void UWBP_IDE::NativeDestruct()
{
	// destroy Widget when RemoveFromParent()
	
	FPicoCModule::OnDigitalWrite.Unbind();

	Super::NativeDestruct();
}

void UWBP_IDE::ResetCodeTemplate()
{
	if (CodingSection)
	{
		FString TemplateCode = TEXT("void setup() {\n  // put your setup code here, to run once:\n}\n\nvoid loop() {\n  // put your main code here, to run repeatedly:\n}");
		CodingSection->SetText(FText::FromString(TemplateCode));
	}
}

void UWBP_IDE::CodeToPicoC()
{
	// Have CodingSection?
	if (!CodingSection)
	{
		UE_LOG(LogTemp, Warning, TEXT("=== No codeing section ==="));
		return;
	}
	UE_LOG(LogTemp, Warning, TEXT("WB_IDE (CodeToPicoC): in CodeToPicoC"));
	
	Results.Empty();

	FString CodeString = CodingSection->GetText().ToString();
	
	FPicoCModule& Module = FPicoCModule::Get();
	UE_LOG(LogTemp, Warning, TEXT("Module Loaded"));

	// FPicoCModule::Get().Compile(CodeString);
	Module.Compile(CodeString);
	
	UE_LOG(LogTemp, Warning, TEXT("CodeToPicoC: %s"), *CodeString);
}

TMap<FString, int32> UWBP_IDE::GetCodeResults()
{
	return Results;
}

void UWBP_IDE::DelayFunction(int32 time)
{
	UE_LOG(LogTemp, Warning, TEXT("Delay (cpp) time(ms): %d"), time);
	if (Delay.IsBound())
	{
		Delay.Broadcast(time);
	}
}

void UWBP_IDE::DigitalWriteFunction(int32 pin,int32 value)
{
	UE_LOG(LogTemp, Warning, TEXT("DigitalWrite (cpp) Pin: %d -> Value: %d"), pin, value);
	if (DigitalWrite.IsBound())
	{
		DigitalWrite.Broadcast(pin, value);
	}
}

void UWBP_IDE::PinModeFunction(int32 pin, int32 value)
{
	UE_LOG(LogTemp, Warning, TEXT("PinMode (cpp) Pin: %d -> Value: %d"), pin, value);
	if (PinMode.IsBound())
	{
		PinMode.Broadcast(pin, value);
	}
}

void UWBP_IDE::DigitalReadFuction(int32 pin)
{
	UE_LOG(LogTemp, Warning, TEXT("digitalRead (cpp) pin: %d"), pin);
	if (DigitalRead.IsBound())
	{
		DigitalRead.Broadcast(pin);
	}
}
