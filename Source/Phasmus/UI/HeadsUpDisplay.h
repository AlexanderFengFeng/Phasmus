// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HeadsUpDisplay.generated.h"

/**
 * 
 */
UCLASS()
class PHASMUS_API UHeadsUpDisplay : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* InteractPrompt;

protected:
	virtual bool Initialize() override;

public:
	UFUNCTION(BlueprintCallable, Category = Prompts)
	void UpdateInteractPromptVisibility(bool bMakeVisible);

};
