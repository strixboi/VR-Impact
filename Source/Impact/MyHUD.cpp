// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"



void AMyHUD::DrawHUD()
{
	Super::DrawHUD();

	if (CrosshairTexture)
	{
		//srodek ekranu
		FVector2D Center(Canvas->ClipX * 0.5f, Canvas->ClipY * 0.5f);

		//Offset 
		FVector2D CrossHairDrawPosition(Center.X - (CrosshairTexture->GetSurfaceWidth()*0.5f), Center.Y - (CrosshairTexture->GetSurfaceHeight()*0.5f));

		//narysuj celownik
		FCanvasTileItem TileItem(CrossHairDrawPosition, CrosshairTexture->Resource, FLinearColor::White);
		TileItem.BlendMode = SE_BLEND_Translucent;
		Canvas->DrawItem(TileItem);
	}
}