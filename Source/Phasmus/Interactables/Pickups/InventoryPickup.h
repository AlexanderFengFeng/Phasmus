// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Interactable.h"
#include "InventoryPickup.generated.h"

/**
 * 
 */
UCLASS()
class PHASMUS_API AInventoryPickup : public AInteractable
{
	GENERATED_BODY()

protected:
	void BeginPlay() override;

public:
	UFUNCTION()
	void AddToInventory(APhasmusPlayerCharacter* PlayerCharacter);
	
};
