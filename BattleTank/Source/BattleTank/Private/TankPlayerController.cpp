// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	GetControlledTank();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	if (GetPawn() != nullptr) {
		FString pawnName = GetPawn()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Possed tank: %s"), *pawnName);
	}
	return Cast<ATank>(GetPawn());
}