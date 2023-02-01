// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "FlashlightPickup.generated.h"

/**
 * 
 */
UCLASS()
class PHASMUS_API AFlashlightPickup : public APickup
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AFlashlight> FlashlightClass;

public:
	virtual void HandleInteraction(APhasmusPlayerCharacter* PlayerCharacter) override;

};
