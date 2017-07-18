// Copyright Scaleno LTD.

#include "BattleTank.h"
#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h" // Needed to implement OnDeath

void ATankAIController::BeginPlay()

{
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn* InPawn)
{

	
	Super::SetPawn(InPawn); // If not called super whole things will not be called in this object
	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }

		//TODO subscribe our local method to the Tank Death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossedTankDeath);
		
	}

}

void ATankAIController::OnPossedTankDeath()
{
	if (!ensure(GetPawn())) { return; } // TODO remove if ok
	
	GetPawn()->DetachFromControllerPendingDestroy();
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






