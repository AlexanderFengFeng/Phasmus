// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractComponent.h"

UInteractComponent::UInteractComponent()
{
    OnComponentBeginOverlap.AddDynamic(this, &UInteractComponent::OnSphereBeginOverlap);
    OnComponentEndOverlap.AddDynamic(this, &UInteractComponent::OnSphereEndOverlap);
}

void UInteractComponent::BeginPlay()
{

}

/**
 * Dynamic delegate called when a component overlaps with the sphere collider.
 */
void UInteractComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    
}

/**
 * Dynamic delegate called when a component stops overlapping with the sphere collider.
 */
void UInteractComponent::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    
}
