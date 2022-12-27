// Fill out your copyright notice in the Description page of Project Settings.


#include "PhasmusPlayerCharacter.h"
#include "Components/CapsuleComponent.h"


// Sets default values
APhasmusPlayerCharacter::APhasmusPlayerCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APhasmusPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APhasmusPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APhasmusPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Bind movement events
	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &APhasmusPlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &APhasmusPlayerCharacter::MoveRight);

	// Bind looking events using mouse
	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &APawn::AddControllerPitchInput);
}

void APhasmusPlayerCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void APhasmusPlayerCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), Value);
	}
}

