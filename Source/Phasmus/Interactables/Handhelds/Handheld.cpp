// Fill out your copyright notice in the Description page of Project Settings.


#include "Handheld.h"

// Sets default values for this component's properties
AHandheld::AHandheld()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMesh);
}

void AHandheld::BeginPlay()
{
	Super::BeginPlay();
}
