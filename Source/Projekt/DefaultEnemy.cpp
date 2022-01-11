// Fill out your copyright notice in the Description page of Project Settings.


#include "DefaultEnemy.h"

// Sets default values
ADefaultEnemy::ADefaultEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	health = 1.0f;
	hasTakenDamage = false;
	isDead = false;
}

// Called when the game starts or when spawned
void ADefaultEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADefaultEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADefaultEnemy::TakeDamage(float _damage)
{
	health -= _damage;

	if (health <= 0.0f)
	{
		isDead = true;
	}
	else
	{
		hasTakenDamage = true;
	}
}