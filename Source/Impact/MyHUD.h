// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "Engine/Canvas.h" 
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class IMPACT_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
protected:
	//Narysuj na srodku celownik
	UPROPERTY(EditDefaultsOnly)
		UTexture2D* CrosshairTexture;
public:

	virtual void DrawHUD() override;



};