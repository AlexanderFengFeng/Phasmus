// Fill out your copyright notice in the Description page of Project Settings.


#include "PickUpComponent.h"

void UPickUpComponent::BeginPlay()
{
    OnComponentBeginOverlap.AddDynamic(this, &UPickUpComponent::OnSphereBeginOverlap);
    OnComponentEndOverlap.AddDynamic(this, &UPickUpComponent::OnSphereEndOverlap);
}

/**
 * Dynamic delegate called when a component overlaps with the sphere collider.
 */
void UPickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    
}

/**
 * Dynamic delegate called when a component stops overlapping with the sphere collider.
 */
void UPickUpComponent::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    
}
