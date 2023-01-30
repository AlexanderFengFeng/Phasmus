// Fill out your copyright notice in the Description page of Project Settings.


#include "Flashlight.h"
#include "Components/PointLightComponent.h"
#include "Components/SpotLightComponent.h"
#include "../../PhasmusPlayerCharacter.h"

AFlashlight::AFlashlight()
{
    SpotLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SpotLight"));
    SpotLight->SetupAttachment(RootComponent);
}

void AFlashlight::BeginPlay()
{
    Super::BeginPlay();
    bIsOn = false;
    SpotLight->SetVisibility(false);
}

void AFlashlight::HandleAction()
{
    if (SpotLight == nullptr) return;

    if (bIsOn)
    {
        bIsOn = false;
        SpotLight->SetVisibility(false);
    }
    else
    {
        bIsOn = true;
        SpotLight->SetVisibility(true);
    }
}

void AFlashlight::BindAction(APhasmusPlayerCharacter* TargetCharacter)
{
    Character = TargetCharacter;
    if (Character != nullptr)
    {
        Character->OnUseFlashlight.AddDynamic(this, &AFlashlight::HandleAction);
    }
}
