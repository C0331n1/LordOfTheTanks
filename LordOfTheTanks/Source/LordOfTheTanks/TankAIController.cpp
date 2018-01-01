// Fill out your copyright notice in the Description page of Project Settings.

#include "LordOfTheTanks.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing a tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing: %s"), *(ControlledTank->GetName())
		);
	}
}

AATank* ATankAIController::GetControlledTank() const
{

	return Cast<AATank>(GetPawn());
}

