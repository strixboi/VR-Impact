// Fill out your copyright notice in the Description page of Project Settings.


#include "ImpactCharacter.h"

// Sets default values
AImpactCharacter::AImpactCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//FPScamera components
	FPSCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	check(FPSCameraComponent != nullptr);

	//Przytwierdzi kamere
	FPSCameraComponent->SetupAttachment(CastChecked<USceneComponent, UCapsuleComponent>(GetCapsuleComponent()));

	//Kamera na poziomie oczu
	FPSCameraComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 50.0f + BaseEyeHeight));

	//Pozwol na rotacje kamery
	FPSCameraComponent->bUsePawnControlRotation = true;

	//Stworz fps mesh
	FPSMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FirstPersonMesh"));
	check(FPSMesh != nullptr);

	//widoczne tylko dla gracza
	FPSMesh->SetOnlyOwnerSee(true);

	//Przypnij do kamery
	FPSMesh->SetupAttachment(FPSCameraComponent);

	//Wylacz cienie
	FPSMesh->bCastDynamicShadow = false;
	FPSMesh->CastShadow = false;

	//gracz nie widzi trzeciej osoby
	GetMesh()->SetOwnerNoSee(true);

}

// Called when the game starts or when spawned
void AImpactCharacter::BeginPlay()
{
	Super::BeginPlay();

	check(GEngine != nullptr);

	//wyswietl info, ze character jest uzyty
	GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, TEXT("ImpactCharacter is used!"));

	
}

// Called every frame
void AImpactCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AImpactCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//bindy poruszanie
	PlayerInputComponent->BindAxis("MoveForward", this, &AImpactCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AImpactCharacter::MoveRight);
	//bindy kamera pierwszoosobowa
	PlayerInputComponent->BindAxis("Turn", this, &AImpactCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AImpactCharacter::AddControllerPitchInput);
	//bindy skok
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AImpactCharacter::StartJump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &AImpactCharacter::StopJump);
	//bindy fire
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AImpactCharacter::Fire);

}


void AImpactCharacter::MoveForward(float Value)
{
	//ktory jest do przodu a ktory do tylu?
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);

}

void AImpactCharacter::MoveRight(float Value)
{
	//ktory do prawej a ktory do lewej?
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AImpactCharacter::StartJump()
{
	bPressedJump = true;
}

void AImpactCharacter::StopJump()
{
	bPressedJump = false;
}

void AImpactCharacter::Fire()
{
	//strzel
	if (ProjectileClass)
	{
		//get camera transform
		FVector CameraLocation;
		FRotator CameraRotation;
		GetActorEyesViewPoint(CameraLocation, CameraRotation);

		//Offset przed oczy
		MuzzleOffset.Set(100.0f, 0.0f, 0.0f);

		//Transform Offset do world location
		FVector MuzzleLocation = CameraLocation + FTransform(CameraRotation).TransformVector(MuzzleOffset);

		FRotator MuzzleRotation = CameraRotation;
		MuzzleRotation.Pitch += 10.0f;

		UWorld* World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();

			//spawn projectile on the muzzle for fucks sake
			AImpactProjectile* Projectile = World->SpawnActor<AImpactProjectile>(ProjectileClass, MuzzleLocation, MuzzleRotation, SpawnParams);

			if (Projectile)
			{
				//ustaw trajektorie
				FVector LaunchDirection = MuzzleRotation.Vector();
				Projectile->FireInDirection(LaunchDirection);
			}
		}


	}
}