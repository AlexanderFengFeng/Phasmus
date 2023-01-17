// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Phasmus/PhasmusPlayerCharacter.h"
#include "InteractComponent.generated.h"

// TODO: Rename to FOnPickUp once there is no conflict.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteract, APhasmusPlayerCharacter*, PickUpCharacter);

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PHASMUS_API UInteractComponent : public USphereComponent
{
	GENERATED_BODY()

public:

	UInteractComponent();

	//UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnInteract OnIntearct;

protected:

	/** Called when the game starts. */
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
};
