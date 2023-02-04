// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../PhasmusPlayerCharacter.h"
#include "GameFramework/Actor.h"
#include "Interactable.generated.h"

class APhasmusPlayerCharacter;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInteract, APhasmusPlayerCharacter*, PlayerCharacter);

UCLASS()
class PHASMUS_API AInteractable : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* StaticMesh;
	
public:	
	// Sets default values for this actor's properties
	AInteractable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* InteractableComponent;
    

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintAssignable, Category = Interaction)
	FOnInteract OnInteract;
};
