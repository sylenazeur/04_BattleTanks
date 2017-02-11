// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	// Example of assigning a variable as a Pointer
	// Validation to see if there is a possessed pointer pawn
	// If yes, sends out text to show name of possessed pawn
	// using the variable assigned, and * to denote conversion to TChar
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		//UE_LOG(LogTemp, Warning, TEXT("AI not possessing a tank"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("AI possessing %s"), *(ControlledTank->GetName()));
	}

	// New variable that is assigned return value from GetPlayerTank()
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		//UE_LOG(LogTemp, Warning, TEXT("No player tank"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("AI looking at %s"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		// TODO: Move Towards the player
		// Aim towards the player
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
		// Fire if ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}


