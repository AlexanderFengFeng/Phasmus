// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HeldItemComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PHASMUS_API UHeldItemComponent : public USceneComponent
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Components)
	UStaticMeshComponent* FirstPersonStaticMesh;

public:	
	// Sets default values for this component's properties
	UHeldItemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
