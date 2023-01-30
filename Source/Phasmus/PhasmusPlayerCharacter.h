// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PhasmusPlayerCharacter.generated.h"

class APhasmusPlayerController;
//class AFlashlight;

class UCameraComponent;
class UHeadsUpDisplay;
class USkeletalMeshComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnUseFlashlight);

UCLASS(config=Game)
class PHASMUS_API APhasmusPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = Mesh)
	USkeletalMeshComponent* FirstPersonMesh;

	UPROPERTY(EditAnywhere, Category = Gameplay)
	class UPlayerInteractComponent* InteractComponent;

	UPROPERTY(EditAnywhere, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	/** Move after prototyping */
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class AFlashlight> FlashlightClass;

	APhasmusPlayerController* Controller;
	void AssignPlayerController();

	// Handles moving forward/backward
	void MoveForward(float Value);
	// Handles strafing movement, left and right
	void MoveRight(float Value);
	// Handles looking around. Linked to look sensitivity
	void LookUp(float Value);
	void LookRight(float Value);
	void Interact();
	void UseFlashlight();

	UPROPERTY(EditAnywhere)
	float LookSensitivity = 0.4f;

public:
    // Sets default values for this character's properties
	APhasmusPlayerCharacter();

    void SetUpFirstPerson();
    void SetUpThirdPerson();
    void SetUpGameplay();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UHeadsUpDisplay* GetHUD();

	UPROPERTY(BlueprintAssignable, Category = Interaction)
	FOnUseFlashlight OnUseFlashlight;
};
