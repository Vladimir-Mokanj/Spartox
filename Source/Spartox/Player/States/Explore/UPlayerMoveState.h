// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "UPlayerBaseState.h"
#include "UPlayerMoveState.generated.h"

UCLASS(Blueprintable)
class SPARTOX_API UUPlayerMoveState : public UUPlayerBaseState
{
	GENERATED_BODY()

protected:
	virtual void EnterState(AActor* StateOwner) override;
	virtual void TickState(const float DeltaTime) override;
};
