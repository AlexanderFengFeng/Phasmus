// Fill out your copyright notice in the Description page of Project Settings.


#include "FlashlightPickup.h"

#include "../Handhelds/Flashlight.h"
#include "Character/PhasmusPlayerCharacter.h"

void AFlashlightPickup::BeginPlay()
{
    Super::BeginPlay();
    OnInteract.AddDynamic(this, &AFlashlightPickup::AttachFlashlightToCharacter);
}

void AFlashlightPickup::AttachFlashlightToCharacter(APhasmusPlayerCharacter* PlayerCharacter)
{
    if (FlashlightClass != nullptr && PlayerCharacter != nullptr)
    {
        FActorSpawnParameters ActorSpawnParams;
        USceneComponent* Anchor = PlayerCharacter->GetRightHandAnchor();
        if (Anchor == nullptr) return;

        AFlashlight* Flashlight = GetWorld()->SpawnActor<AFlashlight>(
            FlashlightClass, Anchor->GetComponentLocation(),
            Anchor->GetComponentRotation(), ActorSpawnParams);

        FAttachmentTransformRules AttachmentRules(EAttachmentRule::SnapToTarget, true);
        Flashlight->AttachToComponent(Anchor, AttachmentRules);
        Flashlight->BindAction(PlayerCharacter);
    }
    Destroy();
}