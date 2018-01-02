// Fill out your copyright notice in the Description page of Project Settings.

#include "LordOfTheTanks.h"
#include "ATankPlayerController.h"

void AATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName())
			);
	}
}

void AATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	///UE_LOG(LogTemp, Warning, TEXT("PlayerController Ticking"));
	AimTowardsCrosshair();
}

AATank* AATankPlayerController::GetControlledTank() const 
{
	
	return Cast<AATank>(GetPawn());
}

void AATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	// Get world location if linetrace through crosshair
	//If it hits the landscape
		//Tell controlled tank to aim at this point
}