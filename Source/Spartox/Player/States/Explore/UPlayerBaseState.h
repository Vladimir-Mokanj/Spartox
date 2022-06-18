// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "Spartox/Core/States/UStateBase.h"
#include "Spartox/Player/APlayerBase.h"
#include "Spartox/Player/Interfaces/IPlayerClickInteract.h"
#include "UPlayerBaseState.generated.h"


UCLASS()
class SPARTOX_API UUPlayerBaseState : public UUStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
		AAPlayerBase* PlayerRef = nullptr;

	IIPlayerClickInteract* PlayerController = nullptr;
	virtual void EnterState(AActor* OwnerRef) override;
	virtual void ExitState() override;

protected:
	virtual void MouseClick();
};