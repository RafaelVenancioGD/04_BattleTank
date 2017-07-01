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

private:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;

	// Hot long can AI Tank get closer to the player
	float AcceptanceRadius = 3000;
};
