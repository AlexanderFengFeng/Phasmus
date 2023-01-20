// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInteractComponent.h"

#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "Interactables/Interactable.h"
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

	OnComponentBeginOverlap.AddDynamic(this, &UPlayerInteractComponent::OnSphereBeginOverlap);
    OnComponentEndOverlap.AddDynamic(this, &UPlayerInteractComponent::OnSphereEndOverlap);
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
	ChosenInteractable = GetClosestInteractable();
	ShowInteractPromptIfNeeded();
}

void UPlayerInteractComponent::ShowInteractPromptIfNeeded()
{
    if (PlayerOwner == nullptr) return;
    UHeadsUpDisplay* HUD = PlayerOwner->GetHUD();

    if (ChosenInteractable != nullptr && HUD != nullptr)
    {
        HUD->UpdateInteractPromptVisibility(true);
    }
    else if (HUD != nullptr)
    {
        HUD->UpdateInteractPromptVisibility(false);
    }
}

/**
 * Dynamic delegate called when a component overlaps with the sphere collider.
 */
void UPlayerInteractComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (PlayerOwner == nullptr) return;

	if (AInteractable* Interactable = Cast<AInteractable>(OtherActor))
	{
		OverlappedInteractables.Add(Interactable);
	}
}

/**
 * Dynamic delegate called when a component stops overlapping with the sphere collider.
 */
void UPlayerInteractComponent::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (PlayerOwner == nullptr) return;

	if (AInteractable* Interactable = Cast<AInteractable>(OtherActor))
	{
		if (!OverlappedInteractables.Contains(Interactable)) return;
		OverlappedInteractables.Remove(Interactable);
	}
}

bool UPlayerInteractComponent::HasClearLineOfSight(AActor* OtherActor, float& OutDistance)
{
	if (FirstPersonCameraComponent == nullptr || OtherActor == nullptr) return false;

	FVector Start = FirstPersonCameraComponent->GetComponentLocation();
	FVector End = OtherActor->GetActorLocation();
	OutDistance = FVector::Dist(Start, End);

	FHitResult HitResult;
	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(PlayerOwner); // Ignore Actor1 in the trace
	QueryParams.AddIgnoredActor(OtherActor); // Ignore Actor2 in the trace

	return GetWorld()->LineTraceSingleByChannel(HitResult, Start, End,
		                                        ECC_Visibility, QueryParams);
}

AInteractable* UPlayerInteractComponent::GetClosestInteractable()
{
	if (OverlappedInteractables.IsEmpty()) return nullptr;

	AInteractable* CurrentClosest = nullptr;
	float MinDistance = MAX_int8;
	for (AInteractable* Interactable : OverlappedInteractables)
	{
		if (Interactable == nullptr) continue;
		float OutDistance = MAX_int8;
	    if (HasClearLineOfSight(Interactable, OutDistance))
	    {
	        if (OutDistance < MinDistance)
	        {
				MinDistance = OutDistance;
				CurrentClosest = Interactable;
	        }
	    }
	}
	return CurrentClosest;
}
