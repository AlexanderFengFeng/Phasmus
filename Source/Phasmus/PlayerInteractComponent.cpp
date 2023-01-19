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
	//LookForInteractable();
}

void UPlayerInteractComponent::LookForInteractable()
{
	if (FirstPersonCameraComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Error: First-person camera component is required"));
		return;
	}
	FVector Start = FirstPersonCameraComponent->GetComponentLocation();
	FVector ForwardVector = FirstPersonCameraComponent->GetForwardVector();
	FVector End = Start + (ForwardVector * InteractDistance);
	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);

	FHitResult HitResult;
	FCollisionQueryParams CollisionParams;
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_GameTraceChannel1, CollisionParams))
	{
	    if (GEngine)
	    {
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("You are hitting: %s"), *HitResult.GetActor()->GetName()));
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("Impact Point: %s"), *HitResult.ImpactPoint.ToString()));
			GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Red, FString::Printf(TEXT("Normal Point: %s"), *HitResult.ImpactNormal.ToString()));
	    }
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
		OverlappedActors.Add(Interactable);
		auto HUD = PlayerOwner->GetHUD();
		if (HUD != nullptr)
		{
			HUD->UpdateInteractPromptVisibility(true);
		}
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
		if (!OverlappedActors.Contains(Interactable)) return;
		OverlappedActors.Remove(Interactable);
	}
	if (OverlappedActors.IsEmpty())
	{
		auto HUD = PlayerOwner->GetHUD();
		if (HUD != nullptr)
		{
		    HUD->UpdateInteractPromptVisibility(false);
		}
	}

}