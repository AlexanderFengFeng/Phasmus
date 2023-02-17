// Fill out your copyright notice in the Description page of Project Settings.


#include "Interactable.h"
#include "Components/BoxComponent.h"


// Sets default values
AInteractable::AInteractable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMesh);
	InteractableComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("InteractableComponent"));
	InteractableComponent->SetGenerateOverlapEvents(true);
	InteractableComponent->SetupAttachment(StaticMesh);
}

// Called when the game starts or when spawned
void AInteractable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

