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
}

void AFlashlight::HandleAction()
{
    
}

void AFlashlight::BindAction(APhasmusPlayerCharacter* TargetCharacter)
{
    Character = TargetCharacter;
    if (Character != nullptr)
    {
        Character->OnUseFlashlight.AddDynamic(this, &AFlashlight::HandleAction);
    }
}