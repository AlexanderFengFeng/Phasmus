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

	UFUNCTION()
	void GrabDoor(APhasmusPlayerCharacter* PlayerCharacter);
	UFUNCTION()
	void ReleaseDoor(APhasmusPlayerCharacter* PlayerCharacter);

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;


};
