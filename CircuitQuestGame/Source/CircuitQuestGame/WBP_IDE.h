// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/MultiLineEditableTextBox.h"
#include "WBP_IDE.generated.h"

/**
 * 
 */
UCLASS()
class CIRCUITQUESTGAME_API UWBP_IDE : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// get text from player
	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	class UMultiLineEditableTextBox* CodingSection;
	
	// UFUNCTION(BlueprintCallable, Category = "IDE Logic")
	// void CodeToPicoC();
	//
	// UFUNCTION(BlueprintCallable, Category = "IDE Logic")
	// TMap<FString, int32> GetCodeResults();
	
	// Arduino function
	// virtual void DigitalWrite(int32 Pin, int32 Value) override;

protected:
	// virtual void NativeConstruct() override;
	// virtual void NativeDestruct() override;
	//
	// void DigitalWriteFunction(int32 Pin, int32 Value);
	// void DelayFunction(int32 time);
	
private:
	// TMap<FString, int32> Results;
};
