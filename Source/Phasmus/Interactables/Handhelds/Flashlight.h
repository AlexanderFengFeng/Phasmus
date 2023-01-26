// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Handheld.h"
#include "Flashlight.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PHASMUS_API AFlashlight : public AHandheld
{
	GENERATED_BODY()

public:
	virtual void HandleAction() override;
	
};
