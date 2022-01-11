// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DefaultEnemy.generated.h"

UCLASS()
class PROJEKT_API ADefaultEnemy : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADefaultEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void TakeDamage(float _damage);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
	float health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
	bool hasTakenDamage;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Enemy)
	bool isDead;





public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
