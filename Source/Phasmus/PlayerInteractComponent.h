// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "PlayerInteractComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PHASMUS_API UPlayerInteractComponent : public USphereComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float InteractDistance = 125.f;

	UPROPERTY(EditAnywhere, Category = Components)
	class UCameraComponent* FirstPersonCameraComponent;
	class APhasmusPlayerCharacter* PlayerOwner;

	void LookForInteractable();

	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	TSet<class AInteractable*> OverlappedActors;

public:
	// Sets default values for this component's properties
	UPlayerInteractComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
