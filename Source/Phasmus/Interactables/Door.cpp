// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

void ADoor::BeginPlay()
{
    Super::BeginPlay();
    DirectionModifier = bOpensCounterClockwise ? 1 : -1;
    ClosedYaw = GetActorRotation().Yaw;
    OpenYaw = ClosedYaw + 90.f * DirectionModifier;
    InitialYaw = ClosedYaw;
    TargetYaw = OpenYaw;
    OnInteract.AddDynamic(this, &ADoor::OpenOrCloseDoor);
}

void ADoor::OpenOrCloseDoor(APhasmusPlayerCharacter* PlayerCharacter)
{
    bIsRotating = true;
    bIsInteractable = false;
}

void ADoor::Tick(float DeltaSeconds)
{
    if (bIsRotating)
    {
        OpenOrCloseDoorOnTick(DeltaSeconds);
    }
}

void ADoor::OpenOrCloseDoorOnTick(float DeltaSeconds)
{
    float NextYaw = GetActorRotation().Yaw + RotationSpeed * DeltaSeconds * DirectionModifier * OpenOrClosingModifier;
    if (FMath::Abs(FMath::FindDeltaAngleDegrees(InitialYaw, NextYaw)) >= 90.f)
    {
        NextYaw = TargetYaw;        // Bound next yaw to the target yaw.
        bIsRotating = false;        // End rotating action.
        bIsClosed = !bIsClosed;     // Change status of door.

        if (bIsCloseable || bIsClosed)  // Only reenable interactions if can be closed after opening.
        {
            bIsInteractable = true;     // Reenable interactions.
            DirectionModifier = -DirectionModifier;
            InitialYaw = bIsClosed ? ClosedYaw : OpenYaw;
            TargetYaw = bIsClosed ? OpenYaw : ClosedYaw;
        }
    }
    SetActorRotation(FRotator(GetActorRotation().Pitch, NextYaw, GetActorRotation().Roll));
}