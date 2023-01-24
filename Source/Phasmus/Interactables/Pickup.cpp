// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"

// Called when the game starts or when spawned
//void APickup::BeginPlay()
//{
//	Super::BeginPlay();
//	
//}
//
//// Called every frame
//void APickup::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

void APickup::HandleInteraction(APhasmusPlayerCharacter* PlayerCharacter)
{
	UE_LOG(LogTemp, Warning, TEXT("PICKING UP: %s"), *this->GetName());
	Destroy();
}
