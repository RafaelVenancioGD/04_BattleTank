// Copyright Scaleno LTD.

#pragma once

#include "AIController.h"
#include "TankAIController.generated.h"

/**
*
*/
UCLASS()

class BATTLETANK_API ATankAIController : public AAIController

{
	GENERATED_BODY()

protected:

	// Hot long can AI Tank get closer to the player
	UPROPERTY(EditDefaultsOnly,Category = "Setup")
	float AcceptanceRadius = 3000;

private:

	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	virtual void Tick(float DeltaSeconds) override;

	UFUNCTION()
	void OnPossedTankDeath();

};
