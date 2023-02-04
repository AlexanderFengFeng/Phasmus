// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryPickup.h"


void AInventoryPickup::BeginPlay()
{
    Super::BeginPlay();
    OnInteract.AddDynamic(this, &AInventoryPickup::AddToInventory);
}

void AInventoryPickup::AddToInventory(APhasmusPlayerCharacter* PlayerCharacter)
{
    Destroy();
}
