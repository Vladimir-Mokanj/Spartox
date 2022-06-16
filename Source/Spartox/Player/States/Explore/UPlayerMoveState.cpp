// Project done by Vladimir Mokanj

#include "UPlayerMoveState.h"

#include "GameFramework/CharacterMovementComponent.h"

void UUPlayerMoveState::TickState(const float DeltaTime)
{
	Super::TickState(DeltaTime);

	const FVector PlayerLocation = PlayerRef->GetActorLocation();
	const FVector TargetLocation = PlayerRef->HitResult.ImpactPoint;

	// Move towards the hit location
	PlayerRef->AddMovementInput(TargetLocation - PlayerLocation, 2.0f, false);

	// Check for distance and switch to idle state
	if (FVector::Distance(TargetLocation, PlayerLocation) <= PlayerRef->MoveDistanceRange)
	{
		PlayerRef->bIsMoving = false;
		PlayerRef->StateManager->SwitchStateByKey("Idle");
	}
}