// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "HeldItemComponent.h"
//#include "PickUpComponent.h"

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HeldItemComponent = CreateDefaultSubobject<UHeldItemComponent>(TEXT("Held Item Component"));
	//PickUpComponent = CreateDefaultSubobject<UPickUpComponent>(TEXT("Pick Up Component"));
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
