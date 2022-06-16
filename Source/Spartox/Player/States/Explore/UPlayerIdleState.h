// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "UPlayerBaseState.h"
#include "UPlayerIdleState.generated.h"

UCLASS(Blueprintable)
class SPARTOX_API UUPlayerIdleState : public UUPlayerBaseState
{
	GENERATED_BODY()

protected:
	virtual void ClickMove() override;
	virtual void TickState(const float DeltaTime) override;

};