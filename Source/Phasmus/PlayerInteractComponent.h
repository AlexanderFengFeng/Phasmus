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
	float DetectionRadius = 40.f;

	UPROPERTY(EditAnywhere, Category = Components)
	class UCameraComponent* FirstPersonCameraComponent;
	class APhasmusPlayerCharacter* PlayerOwner;

	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	TSet<AInteractable*> OverlappedInteractables;
	bool HasClearLineOfSight(AActor* OtherActor, float& OutDistance);
	AInteractable* ChosenInteractable;
	AInteractable* GetClosestInteractable();

public:
	// Sets default values for this component's properties
	UPlayerInteractComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
    bool ShowInteractPromptIfNeeded();

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
