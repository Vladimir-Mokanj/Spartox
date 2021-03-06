// Project done by Vladimir Mokanj

#include "UPlayerMoveState.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"

void UUPlayerMoveState::EnterState(AActor* StateOwner)
{
	Super::EnterState(StateOwner);

	// Get hit point of the raycast
	TargetLocation = PlayerRef->HitResult.ImpactPoint;
}

void UUPlayerMoveState::TickState(const float DeltaTime)
{
	Super::TickState(DeltaTime);

	// Move towards the hit location
	PlayerRef->AddMovementInput(TargetLocation - PlayerRef->GetActorLocation(), 1.5f, false);

	// Check for distance and switch to idle state
	if (FVector::Distance(TargetLocation, PlayerRef->GetActorLocation()) <= PlayerRef->MoveDistanceRange)
	{
		PlayerRef->bIsMoving = false;
		PlayerRef->StateManager->SwitchStateByKey("Idle");
	}
}

void UUPlayerMoveState::MouseClick()
{
	// Raycast hit result
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetHitResultUnderCursor(ECC_WorldStatic, true, PlayerRef->HitResult);
	if (PlayerRef->HitResult.IsValidBlockingHit() == false)
		return;

	// Debug for line trace
	if (PlayerRef->StateManager->bDebug == true)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, PlayerRef->HitResult.ImpactPoint.ToString() + " world location. ", true);
		DrawDebugLine(GetWorld(), PlayerRef->HitResult.Location, PlayerRef->HitResult.Location, FColor(255, 0, 0), true, -1, 0, 12);
	}

	// Switch states
	if (PlayerRef->HitResult.GetActor()->ActorHasTag("Map") == true)
	{
		TargetLocation = PlayerRef->HitResult.ImpactPoint;
	}
	else if (PlayerRef->HitResult.GetActor()->ActorHasTag("Pickup-able") == true)
	{
		PlayerRef->StateManager->SwitchStateByKey("Interact");
	}
}
