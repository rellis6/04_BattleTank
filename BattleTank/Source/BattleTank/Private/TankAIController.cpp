// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	GetControlledTank();

	ATank *player = GetPlayerTank();

	if (player != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Found Player Tank: %s"), *(player->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Didn't find Player Tank"));
	}

}

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}