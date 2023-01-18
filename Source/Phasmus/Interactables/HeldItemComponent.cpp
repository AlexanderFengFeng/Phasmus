// Fill out your copyright notice in the Description page of Project Settings.


#include "HeldItemComponent.h"

// Sets default values for this component's properties
UHeldItemComponent::UHeldItemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	FirstPersonStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("First-Person Static Mesh"));
	//FirstPersonStaticMesh->SetupAttachment(this);
}


// Called when the game starts
void UHeldItemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UHeldItemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

