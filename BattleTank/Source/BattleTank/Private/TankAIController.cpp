// Copyright Scaleno LTD.

#include "BattleTank.h"
#include "TankAIController.h"
#include "TankAimingComponent.h"

void ATankAIController::BeginPlay()

{
	Super::BeginPlay();
}

// Called every frame
void ATankAIController::Tick(float DeltaTime)

{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	// TODO Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius); //TODO Check Radius in centimeters

	// Aim towards the player
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// if aim or locked
	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{

		AimingComponent->Fire();
	}

}






