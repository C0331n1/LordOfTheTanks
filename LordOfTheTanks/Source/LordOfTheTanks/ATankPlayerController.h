// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "ATank.h"
#include "GameFramework/PlayerController.h"
#include "ATankPlayerController.generated.h" ///must be the last #include

/**
 * 
 */
UCLASS()
class LORDOFTHETANKS_API AATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Start the tank moving the barrel so that the shot would hit where 
	// the crosshair intersects the world
	void AimTowardsCrosshair();

};