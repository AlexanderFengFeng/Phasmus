// Fill out your copyright notice in the Description page of Project Settings.


#include "PhasmusPlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Interactables/Interactable.h"
#include "PhasmusPlayerController.h"
#include "PlayerInteractComponent.h"
#include "UI/HeadsUpDisplay.h"


// Sets default values
APhasmusPlayerCharacter::APhasmusPlayerCharacter()
{
	SetUpFirstPerson();
	SetUpThirdPerson();
	SetUpGameplay();
}

void APhasmusPlayerCharacter::SetUpFirstPerson()
{
    // Create and set up the first-person camera component
    FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
    FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 0.f, 64.f));
    FirstPersonCameraComponent->bUsePawnControlRotation = true;

    // Set up first-person mesh
    FirstPersonMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
    FirstPersonMesh->SetupAttachment(FirstPersonCameraComponent);
    FirstPersonMesh->SetOnlyOwnerSee(true);
    FirstPersonMesh->bCastDynamicShadow = false;
    FirstPersonMesh->CastShadow = false;
    FirstPersonMesh->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
    FirstPersonMesh->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
    FirstPersonMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    LeftHandAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("LeftHandAnchor"));
    LeftHandAnchor->SetupAttachment(FirstPersonCameraComponent);
    LeftHandAnchor->SetRelativeLocation(FVector(30.f, -30.f, -25.f));
    RightHandAnchor = CreateDefaultSubobject<USceneComponent>(TEXT("RightHandAnchor"));
    RightHandAnchor->SetupAttachment(FirstPersonCameraComponent);
    RightHandAnchor->SetRelativeLocation(FVector(30.f, 30.f, -25.f));

    InteractComponent = CreateDefaultSubobject<UPlayerInteractComponent>(TEXT("Interact Component"));
    InteractComponent->SetupAttachment(FirstPersonCameraComponent);
}

// Sets up third-person mesh.
void APhasmusPlayerCharacter::SetUpThirdPerson()
{
    USkeletalMeshComponent* ThirdPersonMesh = GetMesh();
    if (ThirdPersonMesh != nullptr)
    {
        ThirdPersonMesh->SetOwnerNoSee(true);
        ThirdPersonMesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
    }
}

void APhasmusPlayerCharacter::SetUpGameplay()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    // Set up movement component
    GetCapsuleComponent()->InitCapsuleSize(40.f, 90.0f);
    if (UCharacterMovementComponent* MovementComponent = GetCharacterMovement())
    {
        MovementComponent->MaxWalkSpeed = 300.f; // in cm/s
        MovementComponent->MaxWalkSpeedCrouched = 150.f; // in cm/s
    }
}

// Called when the game starts or when spawned
void APhasmusPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
    AssignPlayerController();
}

void APhasmusPlayerCharacter::AssignPlayerController()
{
    if (Controller == nullptr)
    {
        if (APhasmusPlayerController* PlayerController = Cast<APhasmusPlayerController>(GetController()))
        {
            Controller = PlayerController;
        }
    }
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

	// Bind action events
    PlayerInputComponent->BindAction("PrimaryAction", IE_Pressed, this, &APhasmusPlayerCharacter::Interact);
    PlayerInputComponent->BindAction("PrimaryAction", IE_Released, this, &APhasmusPlayerCharacter::ReleaseInteraction);
    PlayerInputComponent->BindAction("Flashlight", IE_Pressed, this, &APhasmusPlayerCharacter::UseFlashlight);

	// Bind movement events
	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &APhasmusPlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &APhasmusPlayerCharacter::MoveRight);

	// Bind looking events using mouse
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &APhasmusPlayerCharacter::LookUp);
	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &APhasmusPlayerCharacter::LookRight);
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

void APhasmusPlayerCharacter::LookUp(float Value)
{
    LookUpRate = Value;
	AddControllerPitchInput(Value * LookSensitivity);
}

void APhasmusPlayerCharacter::LookRight(float Value)
{
    LookRightRate = Value;
	AddControllerYawInput(Value * LookSensitivity);
}

void APhasmusPlayerCharacter::Interact()
{
    ChosenInteractable = InteractComponent->GetChosenInteractable();
    if (ChosenInteractable != nullptr)
    {
        ChosenInteractable->OnInteract.Broadcast(this);
    }
}

/** Releases the chosen interactable from its interaction, then unassign its pointer. */
void APhasmusPlayerCharacter::ReleaseInteraction()
{
    if (ChosenInteractable != nullptr)
    {
        ChosenInteractable->OnReleaseInteraction.Broadcast(this);
        ChosenInteractable = nullptr;
    }
}

void APhasmusPlayerCharacter::UseFlashlight()
{
    OnUseFlashlight.Broadcast();
}

UHeadsUpDisplay* APhasmusPlayerCharacter::GetHUD()
{
    AssignPlayerController();
    return Controller != nullptr ? Controller->GetHUD() : nullptr;
}
