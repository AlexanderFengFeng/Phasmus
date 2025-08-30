#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HeadsUpDisplay.generated.h"

class UTextBlock;

// HUD for the player.
UCLASS()
class PHASMUS_API UHeadsUpDisplay : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual bool Initialize() override;

public:
	UFUNCTION(BlueprintCallable, Category = Prompts)
	void UpdateInteractPromptVisibility(bool bMakeVisible);

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UTextBlock> InteractPrompt;

};
