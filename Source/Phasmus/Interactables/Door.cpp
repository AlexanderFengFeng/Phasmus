// Fill out your copyright notice in the Description page of Project Settings.


#include "Door.h"

void ADoor::BeginPlay()
{
    Super::BeginPlay();
    ClosedYaw = GetActorRotation().Yaw;
    OnInteract.AddDynamic(this, &ADoor::OpenDoor);
}


void ADoor::OpenDoor(APhasmusPlayerCharacter* PlayerCharacter)
{
    UE_LOG(LogTemp, Warning, TEXT("ClosedYaw: %f"), ClosedYaw);
    bIsRotating = true;
    bIsInteractable = false;
}

void ADoor::Tick(float DeltaSeconds)
{
    if (bIsRotating)
    {
        float TargetYaw = GetActorRotation().Yaw + RotationSpeed * DeltaSeconds;
        UE_LOG(LogTemp, Warning, TEXT("ClosedYaw: %f"), ClosedYaw);
        UE_LOG(LogTemp, Warning, TEXT("Diff: %f"), FMath::FindDeltaAngleDegrees(TargetYaw, ClosedYaw));
        if (FMath::FindDeltaAngleDegrees(TargetYaw, ClosedYaw) >= 90.f)
        //if (FMath::Abs(FMath::FindDeltaAngleDegrees(TargetYaw, ClosedYaw)) >= 90.f)
        {
            TargetYaw = ClosedYaw + 90.f;
            bIsRotating = false;
            bIsInteractable = true;
        }
        //UE_LOG(LogTemp, Warning, TEXT("TargetYaw2: %f"), TargetYaw);
        SetActorRotation(FRotator(GetActorRotation().Pitch, TargetYaw, GetActorRotation().Roll));
        //AddActorLocalRotation(FRotator(0.f, TargetYaw, 0.f));

        //FRotator NewRelativeRotation = (GetActorRotation())
        //SetActorRelativeRotation()
    }
}