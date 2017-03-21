// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	GetControlledTank();

	ATank *player = GetPlayerTank();

	if (player != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Found Player Tank: %s"), *(player->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Didn't find Player Tank"));
	}

}

ATank* ATankAIController::GetControlledTank() const
{
	if (GetPawn() != nullptr) {
		FString pawnName = GetPawn()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Possed AI tank: %s"), *pawnName);
	}
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}