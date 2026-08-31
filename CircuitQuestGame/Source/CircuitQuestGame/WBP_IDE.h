// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/MultiLineEditableTextBox.h"
#include "WBP_IDE.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOneParamFunction, int32, value);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnTwoParamFunction, int32, pin, int32, value);

UCLASS()
class CIRCUITQUESTGAME_API UWBP_IDE : public UUserWidget
{
	GENERATED_BODY()
	
public:
	// get text from player
	UPROPERTY(meta = (BindWidget), BlueprintReadOnly)
	class UMultiLineEditableTextBox* CodingSection;
	
	UFUNCTION(BlueprintCallable, Category = "IDE Logic")
	void CodeToPicoC();
	
	UFUNCTION(BlueprintCallable, Category = "IDE Logic")
	TMap<FString, int32> GetCodeResults();
	
	UPROPERTY(BlueprintAssignable, Category = "Arduino Events")
    FOnOneParamFunction Delay;
	
	UPROPERTY(BlueprintAssignable, Category = "Arduino Events")
	FOnOneParamFunction DigitalRead;
 	
	UPROPERTY(BlueprintAssignable, Category = "Arduino Events")
	FOnTwoParamFunction DigitalWrite;
	
	UPROPERTY(BlueprintAssignable, Category = "Arduino Events")
	FOnTwoParamFunction PinMode;

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
	
	UFUNCTION(BlueprintCallable, Category = "IDE")
	void ResetCodeTemplate();
	
	void DelayFunction(int32 time);
	void DigitalReadFuction(int32 pin);
	void DigitalWriteFunction(int32 pin, int32 value);
	void PinModeFunction(int32 pin, int32 value);
	
private:
	TMap<FString, int32> Results;
};
