// Copyright Scaleno LTD.

#pragma once

#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" // Put new includes above

// Foward declarations
class UTankBarrel;
class UTankAimingComponent;
class UTankMovementComponent;
class UTankTurret;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

protected:
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	UTankAimingComponent* TankAimingComponent = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	UTankMovementComponent* TankMovementComponent = nullptr;
	
private:
	// Sets default values for this pawn's properties
	ATank();
	
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000; // TODO find sensible default

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3;
	
	double LastFireTime = 0;

	UPROPERTY(EditAnywhere, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel* Barrel = nullptr; //TODO Remove
	
};