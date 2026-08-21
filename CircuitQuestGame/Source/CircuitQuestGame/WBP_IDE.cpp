// Fill out your copyright notice in the Description page of Project Settings.


#include "WBP_IDE.h"
#include "PicoC.h"

void UWBP_IDE::NativeConstruct()
{
	Super::NativeConstruct();
	
	// FPicoCModule::SetBridge(this);
	
	FPicoCModule::OnDigitalWrite.BindUObject(this, &UWBP_IDE::DigitalWriteFunction);
	FPicoCModule::OnDelay.BindUObject(this, &UWBP_IDE::DelayFunction);
}

void UWBP_IDE::NativeDestruct()
{
	// destroy Widget when RemoveFromParent()
	
	FPicoCModule::OnDigitalWrite.Unbind();

	Super::NativeDestruct();
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
	Results.Add(TEXT("Delay"), time);
}

void UWBP_IDE::DigitalWriteFunction(int32 Pin,int32 Value)
{
	UE_LOG(LogTemp, Warning, TEXT("DigitalWrite (cpp) Pin: %d -> Value: %d"), Pin, Value);
	Results.Add(TEXT("digitalWrite_Pin"), Pin);
	Results.Add(TEXT("digitalWrite_Value"), Value);
}