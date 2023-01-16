// Fill out your copyright notice in the Description page of Project Settings.


#include "PhasmusPlayerController.h"

#include "UI/HeadsUpDisplay.h"
#include "UObject/ConstructorHelpers.h"

APhasmusPlayerController::APhasmusPlayerController()
{
    ConstructorHelpers::FClassFinder<UHeadsUpDisplay> HUDBPClass(TEXT("/Game/Blueprints/UI/WBP_HUD"));
    if (HUDBPClass.Class != nullptr)
    {
        HUDClass = HUDBPClass.Class;
    }
}

void APhasmusPlayerController::BeginPlay()
{
    if (HUDClass == nullptr) return;

    HUD = CreateWidget<UHeadsUpDisplay>(this, HUDClass);
    if (HUD != nullptr)
    {
        HUD->AddToViewport();
    }
}
