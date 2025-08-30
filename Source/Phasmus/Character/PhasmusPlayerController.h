// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PhasmusPlayerController.generated.h"

class UHeadsUpDisplay;

/**
 * 
 */
UCLASS()
class PHASMUS_API APhasmusPlayerController : public APlayerController
{
	GENERATED_BODY()

    TSubclassOf<UHeadsUpDisplay> HUDClass;

	UHeadsUpDisplay* HUD;

public:
	APhasmusPlayerController();

	UHeadsUpDisplay* GetHUD();

protected:
	virtual void BeginPlay() override;
};
