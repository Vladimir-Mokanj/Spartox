// Project done by Vladimir Mokanj

#include "UPlayerInteractState.h"

void UUPlayerInteractState::EnterState(AActor* StateOwner)
{
	Super::EnterState(StateOwner);

	PickupObject();	// Only destroys object for now
}

// Picks-up the object in question (will later do with interfaces.. (if actor implements interface, destroy it, since it's easier to manage and change. Tags can get messy)
void UUPlayerInteractState::PickupObject() const
{
	// Destroy actor if the distance is valid and if hitresult is not null (magic number for now, will have blueprintable class for it later)
	if (PlayerRef->HitResult.GetActor() != nullptr && FVector::Distance(PlayerRef->GetActorLocation(), PlayerRef->HitResult.GetActor()->GetActorLocation()) <= 400)
		PlayerRef->HitResult.GetActor()->Destroy();

	// Go back to idle phase. Will change later
	PlayerRef->StateManager->SwitchStateByKey("Idle");
}
