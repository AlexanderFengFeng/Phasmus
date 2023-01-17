// Fill out your copyright notice in the Description page of Project Settings.


#include "HeadsUpDisplay.h"

#include "Components/TextBlock.h"
#include "Math/Color.h"

bool UHeadsUpDisplay::Initialize()
{
    if (!Super::Initialize()) return false;
    if (InteractPrompt != nullptr)
    {
        UpdateInteractPromptVisibility(true);
    }
    return true;
}

void UHeadsUpDisplay::UpdateInteractPromptVisibility(bool bMakeVisible)
{
    if (InteractPrompt != nullptr) return;
    InteractPrompt->SetOpacity(bMakeVisible ? 1.0f : 0.f);
}
