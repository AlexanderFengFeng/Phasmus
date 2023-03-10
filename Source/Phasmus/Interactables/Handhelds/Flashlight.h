// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Handheld.h"
#include "Flashlight.generated.h"

class APhasmusPlayerCharacter;

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PHASMUS_API AFlashlight : public AHandheld
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	class USpotLightComponent* SpotLight;

	bool bIsOn = false;

public:
	AFlashlight();

protected:
    virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:
	virtual void HandleAction() override;
	virtual void BindAction(APhasmusPlayerCharacter* TargetCharacter) override;
};
