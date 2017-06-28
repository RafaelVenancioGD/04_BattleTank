// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankTrack.h"
#include "TankMovementComponent.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }

	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	// No need to call super as we are replacing the functionality 
	
	auto TankFoward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIFowardIntention = MoveVelocity.GetSafeNormal();
	auto FowardThrow = FVector::DotProduct(TankFoward, AIFowardIntention);

	IntendMoveFoward(FowardThrow);
	//UE_LOG(LogTemp, Warning, TEXT("%s Vectoring to %s"), *TankName, *MoveVelocityString);

}

void UTankMovementComponent::IntendMoveFoward(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);

	//TODO Prevent double speed due to double input
}

void UTankMovementComponent::IntendTurnRight(float Throw)
{
	if (!LeftTrack || !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);

	//TODO Prevent double speed due to double input
}

