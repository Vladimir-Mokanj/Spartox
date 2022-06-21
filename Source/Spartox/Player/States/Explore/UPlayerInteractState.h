// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "UPlayerBaseState.h"
#include "UPlayerInteractState.generated.h"

UCLASS(Blueprintable)
class SPARTOX_API UUPlayerInteractState final : public UUPlayerBaseState
{
	GENERATED_BODY()

protected:
	virtual void EnterState(AActor* StateOwner) override;

private:
	// Picks-up the object in question
	void PickupObject() const;
};
