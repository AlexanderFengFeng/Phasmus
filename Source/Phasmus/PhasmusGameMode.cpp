// Copyright Epic Games, Inc. All Rights Reserved.

#include "PhasmusGameMode.h"
#include "PhasmusCharacter.h"
#include "UObject/ConstructorHelpers.h"

APhasmusGameMode::APhasmusGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_PhasmusPlayerCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
