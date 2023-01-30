// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Handheld.generated.h"

class APhasmusPlayerCharacter;

UCLASS()
class PHASMUS_API AHandheld : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	AHandheld();

protected:
	APhasmusPlayerCharacter* Character;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;

public:
	UFUNCTION()
	virtual void HandleAction() PURE_VIRTUAL(AHandheld::HandleAction, return;);
	virtual void BindAction(APhasmusPlayerCharacter* TargetCharacter) PURE_VIRTUAL(AHandheld::BindAction, return;);
};
