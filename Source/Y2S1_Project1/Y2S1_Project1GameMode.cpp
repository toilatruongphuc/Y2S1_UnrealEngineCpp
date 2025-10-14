// Copyright Epic Games, Inc. All Rights Reserved.

#include "Y2S1_Project1GameMode.h"
#include "Y2S1_Project1Character.h"
#include "UObject/ConstructorHelpers.h"

AY2S1_Project1GameMode::AY2S1_Project1GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
