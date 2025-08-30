#include "PlayerInteractComponent.h"

#include "DrawDebugHelpers.h"
#include "Interactable.h"

#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "Character/PhasmusPlayerCharacter.h"
#include "UI/HeadsUpDisplay.h"

// Sets default values for this component's properties
UPlayerInteractComponent::UPlayerInteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.
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
    if (!IsValid(PlayerOwner))
    	return;
	
	if (auto* HUD = PlayerOwner->GetHUD())
	{
	    if (TracedInteractable != nullptr)
	    {
	        HUD->UpdateInteractPromptVisibility(true);
	    }
	    else
	    {
	        HUD->UpdateInteractPromptVisibility(false);
	    }
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

	const FVector Start = FirstPersonCameraComponent->GetComponentLocation();
	const FVector End = Start + FirstPersonCameraComponent->GetForwardVector() * DetectionDistance;

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