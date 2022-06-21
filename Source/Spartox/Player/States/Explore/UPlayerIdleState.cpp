// Project done by Vladimir Mokanj

#include "UPlayerIdleState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"

void UUPlayerIdleState::EnterState(AActor* StateOwner)
{
	Super::EnterState(StateOwner);
}

void UUPlayerIdleState::TickState(const float DeltaTime)
{
	Super::TickState(DeltaTime);
}

void UUPlayerIdleState::MouseClick()
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

	if (PlayerRef->HitResult.GetActor()->ActorHasTag("Map") == true)
	{
		PlayerRef->bIsMoving = true;
		PlayerRef->StateManager->SwitchStateByKey("Move");
	}
	else if(PlayerRef->HitResult.GetActor()->ActorHasTag("Pickup-able") == true)
	{
		PlayerRef->StateManager->SwitchStateByKey("Interact");
	}
}
