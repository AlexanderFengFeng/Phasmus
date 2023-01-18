// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerInteractComponent.h"

#include "Camera/CameraComponent.h"

// Sets default values for this component's properties
UPlayerInteractComponent::UPlayerInteractComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	Owner = GetOwner();
	if (Owner != nullptr)
	{
		FirstPersonCameraComponent = Owner->FindComponentByClass<UCameraComponent>();
	}
}

// Called when the game starts
void UPlayerInteractComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UPlayerInteractComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	LookForInteractable();
}

void UPlayerInteractComponent::LookForInteractable()
{
	if (FirstPersonCameraComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("Error: First-person camera component is required"));
		return;
	}
	FHitResult HitResult;

	FVector Start = FirstPersonCameraComponent->GetComponentLocation();
	FVector ForwardVector = FirstPersonCameraComponent->GetForwardVector();
	FVector End = Start + (ForwardVector * InteractDistance);
	DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 1, 0, 1);
}