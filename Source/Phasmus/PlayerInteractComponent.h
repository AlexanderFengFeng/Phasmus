// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PlayerInteractComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PHASMUS_API UPlayerInteractComponent : public USceneComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float InteractDistance = 125.f;

	class UCameraComponent* FirstPersonCameraComponent;
	AActor* Owner;

	void LookForInteractable();

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
