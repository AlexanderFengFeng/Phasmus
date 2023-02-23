// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "Door.generated.h"

/**
 * 
 */
UCLASS()
class PHASMUS_API ADoor : public AInteractable
{
	GENERATED_BODY()

    UPROPERTY(EditAnywhere)
    bool bOpensCounterClockwise = false;

	bool bIsRotating = false;
	bool bIsClosed = true;

	UPROPERTY(EditAnywhere)
	bool bIsCloseable = true;
	UPROPERTY(EditAnywhere)
	float RotationSpeed = 90.f;

	int DirectionModifier;			// Sign for angle adjustment when opening door.
	int OpenOrClosingModifier = 1;	// Sign for angle adjustment based on closing or opening.
	float ClosedYaw;				// Initial yaw.
	float OpenYaw;					// Fully open yaw.

	// Dynamic properties.
	float InitialYaw;
	float TargetYaw;

	void OpenOrCloseDoorOnTick(float DeltaSeconds);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

public:
	UFUNCTION()
	void OpenOrCloseDoor(class APhasmusPlayerCharacter* PlayerCharacter);
	
};
