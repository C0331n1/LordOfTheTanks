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

	FVector HitLocation; // Out parameter
	if (GetSightRayHitLocation(HitLocation)) // has side-effect, is going to line trace
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

// Get world location of linetrace through crosshair, true if hits landscape
bool AATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	///UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());

	// de-project the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		// line-trace along that look direction, and see what we hit(up to a max range)
		GetLookVectorHitLocation(LookDirection, HitLocation);	
	}
	
	return true;
}

bool AATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection *LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	return false; //Line trace didnt succeed
}


bool AATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation; // to be discarded
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection);
}
