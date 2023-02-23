// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInteractComponent.h"

#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "DrawDebugHelpers.h"
#include "Interactables/Interactable.h"
#include "Kismet/KismetSystemLibrary.h"
#include "PhasmusPlayerCharacter.h"
#include "UI/HeadsUpDisplay.h"

// Sets default values for this component's properties
UPlayerInteractComponent::UPlayerInteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	SetGenerateOverlapEvents(true);
	SphereRadius = DetectionRadius;
}

// Called when the game starts
void UPlayerInteractComponent::BeginPlay()
{
    Super::BeginPlay();
	PlayerOwner = Cast<APhasmusPlayerCharacter>(GetOwner());
	if (PlayerOwner != nullptr)
	{
		FirstPersonCameraComponent = PlayerOwner->FindComponentByClass<UCameraComponent>();
	}
}

// Called every frame
void UPlayerInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	TraceForInteractable();
	ShowInteractPromptIfNeeded();
}

void UPlayerInteractComponent::ShowInteractPromptIfNeeded()
{
    if (PlayerOwner == nullptr) return;
    UHeadsUpDisplay* HUD = PlayerOwner->GetHUD();
	if (HUD == nullptr) return;

    if (TracedInteractable != nullptr)
    {
        HUD->UpdateInteractPromptVisibility(true);
    }
    else
    {
        HUD->UpdateInteractPromptVisibility(false);
    }
}

/**
 * Traces forward from the player's camera and assigns the first AInteractable hit, if any.
 *
 * If nothing is hit, then nullptr is assigned to the TracedInteractable.
 */
void UPlayerInteractComponent::TraceForInteractable()
{
	if (FirstPersonCameraComponent == nullptr) return;

	FVector Start = FirstPersonCameraComponent->GetComponentLocation();
	FVector End = Start + FirstPersonCameraComponent->GetForwardVector() * DetectionDistance;

	DrawDebugCylinder(GetWorld(), Start, End, DetectionRadius, 8, FColor::Red);
	FHitResult HitResult;
	bool SweepResult = GetWorld()->SweepSingleByChannel(
		HitResult,
		Start,
		End,
		FQuat::Identity,
		ECC_Visibility,
		FCollisionShape::MakeSphere(DetectionRadius));
	if (SweepResult)
	{
		if (AInteractable* CurrentClosest = Cast<AInteractable>(HitResult.GetActor()))
		{
			if (CurrentClosest->IsInteractable())
			{
			    TracedInteractable = CurrentClosest;
			    DrawDebugLine(GetWorld(), GetComponentLocation(), TracedInteractable->GetActorLocation(), FColor::Green, false, 1, 0, 1);
			    return;
			}
		}
	}
	TracedInteractable = nullptr;
}

/** Getter for the traced interactable, if any. */
AInteractable* UPlayerInteractComponent::GetChosenInteractable()
{
	return TracedInteractable;
}
