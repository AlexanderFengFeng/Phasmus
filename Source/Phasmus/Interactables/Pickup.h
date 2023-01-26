// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Pickup.generated.h"

class USphereComponent;

UCLASS()
class PHASMUS_API APickup : public AInteractable
{
	GENERATED_BODY()

public:	
	virtual void HandleInteraction(APhasmusPlayerCharacter* PlayerCharacter) override;

};
