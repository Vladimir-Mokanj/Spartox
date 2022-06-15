// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "Spartox/Core/States/UStateBase.h"
#include "UPlayerBaseState.generated.h"

UCLASS()
class SPARTOX_API UUPlayerBaseState : public UUStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
		class AAPlayerBase* PlayerRef = nullptr;

	class IIPlayerMove* PlayerControllerIfc = nullptr;

	virtual void EnterState(AActor* StateOwner) override;
	virtual void ExitState() override;

protected:
	virtual void ClickMove();
};