// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Interactable.h"
#include "FlashlightPickup.generated.h"

/**
 * 
 */
UCLASS()
class PHASMUS_API AFlashlightPickup : public AInteractable
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AFlashlight> FlashlightClass;

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION()
	void AttachFlashlightToCharacter(APhasmusPlayerCharacter* PlayerCharacter);
};
