// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "PhasmoDoor.generated.h"

class APhasmusPlayerCharacter;
/**
 * 
 */
UCLASS()
class PHASMUS_API APhasmoDoor : public AInteractable
{
	GENERATED_BODY()


	UPROPERTY(EditAnywhere)
	bool bOpensCounterClockwise = true;

	// TODO: Consider allowing doors to be placed in editor already open (not high priority).
	float ClosedDegrees;

	UPROPERTY(EditAnywhere, meta = (ClampMin = "0", ClampMax = "180", UIMin = "0", UIMax = "180"))
	float OpenDegrees = 90.f;

	float MinClampedDegrees;
	float MaxClampedDegrees;

	bool bIsGrabbed = false;

	UFUNCTION()
	void GrabDoor(APhasmusPlayerCharacter* PlayerCharacter);
	UFUNCTION()
	void ReleaseDoor(APhasmusPlayerCharacter* PlayerCharacter);

	APhasmusPlayerCharacter* GrabbingCharacter;
	FVector InitialInFrontForwardVector;
	void MoveDoorOnTick(float DeltaSeconds);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;


};
