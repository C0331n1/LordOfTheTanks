// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ATank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class LORDOFTHETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
	
public:

	virtual void BeginPlay() override;

	AATank* GetControlledTank() const;

	AATank* GetPlayerTank() const;

private:
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
};


