// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IPlayerMove.h"
#include "GameFramework/PlayerController.h"
#include "APlayerControllerBase.generated.h"

UCLASS(Blueprintable)
class SPARTOX_API AAPlayerControllerBase : public APlayerController, public IIPlayerMove
{
	GENERATED_BODY()

public:
	void PressMove();

protected:
	virtual void SetupInputComponent() override;
	virtual FMoveSignature* GetMoveDelegate() override;

private:
	FMoveSignature MoveDelegate;
};