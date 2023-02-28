// Fill out your copyright notice in the Description page of Project Settings.


#include "PhasmoDoor.h"

void APhasmoDoor::BeginPlay()
{
    Super::BeginPlay();
    ClosedDegrees = GetActorRotation().Yaw;
    InitialInFrontForwardVector = -GetActorForwardVector();
    MinClampedDegrees = bOpensCounterClockwise ? ClosedDegrees : ClosedDegrees - OpenDegrees;
    MaxClampedDegrees = bOpensCounterClockwise ? ClosedDegrees + OpenDegrees : ClosedDegrees;

    OnInteract.AddDynamic(this, &APhasmoDoor::GrabDoor);
    OnReleaseInteraction.AddDynamic(this, &APhasmoDoor::ReleaseDoor);
}

void APhasmoDoor::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    MoveDoorOnTick(DeltaSeconds);
}

void APhasmoDoor::GrabDoor(APhasmusPlayerCharacter* PlayerCharacter)
{
    GrabbingCharacter = PlayerCharacter;
    bIsGrabbed = true;
    bIsInteractable = false;
}

void APhasmoDoor::ReleaseDoor(APhasmusPlayerCharacter* PlayerCharacter)
{
    GrabbingCharacter = nullptr;
    bIsGrabbed = false;
    bIsInteractable = true;
}

void APhasmoDoor::MoveDoorOnTick(float DeltaSeconds)
{
    // TODO: Fix issue with door colliding/not colliding properly.
    if (bIsGrabbed && GrabbingCharacter != nullptr)
    {
        // Base sign for horizontally moving the door on the forward vector of the closed Door.
        int PlayerInFrontOfDoorHorizontally = FVector::DotProduct(
            GrabbingCharacter->GetActorLocation() - GetActorLocation(),
            InitialInFrontForwardVector
        ) >= 0 ? 1 : -1;
        // Base sign for vertically moving the door on the current forward vector of the Door.
        int PlayerInFrontOfDoorVertically = FVector::DotProduct(
            GrabbingCharacter->GetActorLocation() - GetActorLocation(),
            -GetActorForwardVector()
        ) >= 0 ? 1 : -1;

        float OpenRateBasedOnHorizontal = GrabbingCharacter->GetLookRightRate() * (bOpensCounterClockwise ? 1 : -1) * PlayerInFrontOfDoorHorizontally;
        // Looking up will open doors.
        float OpenRateBasedOnVertical = -GrabbingCharacter->GetLookUpRate() * PlayerInFrontOfDoorVertically;
        float OpenRate = OpenRateBasedOnHorizontal + OpenRateBasedOnVertical;

        float NextYaw = FMath::ClampAngle(GetActorRotation().Yaw + OpenRate, MinClampedDegrees, MaxClampedDegrees);
        SetActorRotation(FRotator(GetActorRotation().Pitch, NextYaw, GetActorRotation().Roll));
    }
}

