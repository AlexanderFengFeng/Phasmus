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
    bool bOpensClockwise = false;
	bool bIsClosed = true;
	bool bIsRotating = false;

	float ClosedYaw;

	float RotationSpeed = 30.f;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

public:
	UFUNCTION()
	void OpenDoor(class APhasmusPlayerCharacter* PlayerCharacter);
	
};
