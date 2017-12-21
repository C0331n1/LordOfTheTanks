// Fill out your copyright notice in the Description page of Project Settings.

#include "LordOfTheTanks.h"
#include "ATankPlayerController.h"



AATank* AATankPlayerController::GetControlledTank() const 
{
	return Cast<AATank>(GetPawn());
}

