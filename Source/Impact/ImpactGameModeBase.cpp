// Copyright Epic Games, Inc. All Rights Reserved.


#include "ImpactGameModeBase.h"

void AImpactGameModeBase::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);
		

	//wyswietl debug info, ze silnik dziala
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("Hallo operator. Ich wurde gerne einen bruh moment melden!"));

		
}