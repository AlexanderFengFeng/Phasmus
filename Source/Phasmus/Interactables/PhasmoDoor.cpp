// Fill out your copyright notice in the Description page of Project Settings.


#include "PhasmoDoor.h"

void APhasmoDoor::BeginPlay()
{
    Super::BeginPlay();
    OnInteract.AddDynamic(this, &APhasmoDoor::GrabDoor);
    OnReleaseInteraction.AddDynamic(this, &APhasmoDoor::ReleaseDoor);
}

void APhasmoDoor::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
}

void APhasmoDoor::GrabDoor(APhasmusPlayerCharacter* PlayerCharacter)
{
    
}

void APhasmoDoor::ReleaseDoor(APhasmusPlayerCharacter* PlayerCharacter)
{
    
}

