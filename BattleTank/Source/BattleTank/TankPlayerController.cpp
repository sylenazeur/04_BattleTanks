// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));


	// Example of assigning a variable as a Pointer
	// Validation to see if there is a possessed pointer pawn
	// If yes, sends out text to show name of possessed pawn
	// using the variable assigned, and * to denote conversion to TChar
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s"), *(ControlledTank->GetName()));
	}
}
void ATankPlayerController::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	// Get world location if linetrace through crosshair
	GetSightRayHitLocation();

	// If it hits landscape
	if (GetSightRayHitLocation)
	{
		// Tell controlled tank to aim at this point
	}
}

const FHitResult ATankPlayerController::GetSightRayHitLocation()
{

	FVector HitLocation;
	FVector StartLocation;

	/// Ray-cast from player view to landscape
	FHitResult HitResult;
	GetWorld()->LineTraceSingleByObjectType(
		OUT HitResult,
		OUT StartLocation,
		OUT HitLocation,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		FCollisionQueryParams()
	);

	return HitResult;
}
