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

AATank* AATankPlayerController::GetControlledTank() const 
{
	
	return Cast<AATank>(GetPawn());
}

