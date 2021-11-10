// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "ImpactProjectile.h"
#include "ImpactCharacter.generated.h"

UCLASS()
class IMPACT_API AImpactCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AImpactCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Projectile to spawn
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AImpactProjectile> ProjectileClass;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//poruszanie przod tyl
	UFUNCTION()
	void MoveForward(float Value);

	UFUNCTION()
	void MoveRight(float Value);

	UFUNCTION()
	void StartJump();

	UFUNCTION()
	void StopJump();

	//shooting
	UFUNCTION()
	void Fire();
	
	
	//kamera
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* FPSCameraComponent;

	//first person mesh dla gracza
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* FPSMesh;

	//Gun muzzle offset cam loaction
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	FVector MuzzleOffset;

};