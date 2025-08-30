#include "HeadsUpDisplay.h"

#include "Components/TextBlock.h"

bool UHeadsUpDisplay::Initialize()
{
    if (!Super::Initialize()) return false;
    if (IsValid(InteractPrompt))
    {
        UpdateInteractPromptVisibility(false);
    }
    return true;
}

void UHeadsUpDisplay::UpdateInteractPromptVisibility(bool bMakeVisible)
{
    if (IsValid(InteractPrompt))
    {
        InteractPrompt->SetOpacity(bMakeVisible ? 1.0f : 0.f);
    }
}
