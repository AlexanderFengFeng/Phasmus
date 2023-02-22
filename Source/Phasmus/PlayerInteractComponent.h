// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "PlayerInteractComponent.generated.h"

class AInteractable;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PHASMUS_API UPlayerInteractComponent : public USphereComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float DetectionDistance = 100.f;
	UPROPERTY(EditAnywhere)
	float DetectionRadius = 14.f;

	UPROPERTY(EditAnywhere, Category = Components)
	class UCameraComponent* FirstPersonCameraComponent;
	class APhasmusPlayerCharacter* PlayerOwner;

    void ShowInteractPromptIfNeeded();

	TSet<AInteractable*> OverlappedInteractables;
	bool HasClearLineOfSight(AActor* OtherActor, float& OutDistance);
	AInteractable* TracedInteractable;
	void TraceForInteractable();

public:
	// Sets default values for this component's properties
	UPlayerInteractComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	AInteractable* GetChosenInteractable();
};
