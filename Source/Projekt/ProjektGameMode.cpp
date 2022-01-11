// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjektGameMode.h"
#include "ProjektHUD.h"
#include "ProjektCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjektGameMode::AProjektGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AProjektHUD::StaticClass();
}
