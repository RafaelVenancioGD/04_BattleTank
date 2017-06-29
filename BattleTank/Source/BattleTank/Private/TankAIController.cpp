// Copyright Scaleno LTD.

#include "BattleTank.h"
#include "Tank.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()

{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)

{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// TODO Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); //TODO Check Radius in centimeters
		
		// Aim towards the player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		//ControlledTank->Fire(); 
	}

}






