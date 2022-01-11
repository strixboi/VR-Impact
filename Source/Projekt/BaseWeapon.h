// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseWeapon.generated.h"


UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	E_AssaultRifle  UMETA(DisplayName = "ASSAULT_RIFLE"),
	E_Pistol        UMETA(DisplayName = "PISTOL"),
	E_Shotgun       UMETA(DisplayName = "SHOTGUN")
};



UCLASS()
class PROJEKT_API ABaseWeapon : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int maxTotalAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int maxClipAmmo;
		
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int totalAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	int clipAmmo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	float reloadTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Weapon)
	EWeaponType weaponType;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
