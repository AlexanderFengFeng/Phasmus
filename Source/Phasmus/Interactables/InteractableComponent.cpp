// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableComponent.h"

UInteractableComponent::UInteractableComponent()
{
    SetGenerateOverlapEvents(true);
//    OnComponentBeginOverlap.AddDynamic(this, &UInteractableComponent::OnSphereBeginOverlap);
//    OnComponentEndOverlap.AddDynamic(this, &UInteractableComponent::OnSphereEndOverlap);
}
//
///**
// * Dynamic delegate called when a component overlaps with the sphere collider.
// */
//void UInteractableComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//    
//}
//
///**
// * Dynamic delegate called when a component stops overlapping with the sphere collider.
// */
//void UInteractableComponent::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
//{
//    
//}
