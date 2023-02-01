// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Interactable.h"
#include "Pickup.generated.h"

class USphereComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPickup);

UCLASS()
class PHASMUS_API APickup : public AInteractable
{
	GENERATED_BODY()

	UFUNCTION()
	void DestroyPickup();

public:
	APickup();

	UPROPERTY(BlueprintAssignable, Category = Interaction)
	FOnPickup OnPickup;

	virtual void HandleInteraction(APhasmusPlayerCharacter* PlayerCharacter) PURE_VIRTUAL(AInteractable::HandleInteraction, return;);

};
