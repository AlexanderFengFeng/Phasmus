// Fill out your copyright notice in the Description page of Project Settings.


#include "Pickup.h"

APickup::APickup()
{
    OnPickup.AddDynamic(this, &APickup::DestroyPickup);
}


void APickup::DestroyPickup()
{
    Destroy();
}
