// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PhasmusPlayerCharacter.generated.h"

class UCameraComponent;
class USkeletalMeshComponent;

UCLASS(config=Game)
class PHASMUS_API APhasmusPlayerCharacter : public ACharacter
{
	GENERATED_BODY()


	// Use this if we want to include a first-person mesh
	//UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	//USkeletalMeshComponent* FirstPersonMesh;

	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
    USkeletalMeshComponent* ThirdPersonMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	// Handles moving forward/backward
	void MoveForward(float Value);

	// Handles strafing movement, left and right
	void MoveRight(float Value);

public:
	// Sets default values for this character's properties
	APhasmusPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
