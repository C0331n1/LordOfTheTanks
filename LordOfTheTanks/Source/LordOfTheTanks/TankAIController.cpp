// Fill out your copyright notice in the Description page of Project Settings.

#include "LordOfTheTanks.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank!"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName())
		);
	}
}

AATank* ATankAIController::GetControlledTank() const
{

	return Cast<AATank>(GetPawn());
}

AATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController() ->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<AATank>(PlayerPawn);

}

