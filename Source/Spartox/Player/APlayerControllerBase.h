// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IPlayerMove.h"
#include "GameFramework/PlayerController.h"
#include "Interfaces/IPlayerClick.h"
#include "Interfaces/IPlayerClickInteract.h"
#include "APlayerControllerBase.generated.h"

UCLASS(Blueprintable)
class SPARTOX_API AAPlayerControllerBase : public APlayerController, public IIPlayerClickInteract
{
	GENERATED_BODY()

public:
	void MouseClick();

protected:
	virtual void SetupInputComponent() override;
	virtual FClickSig* GetClickDel() override;

private:
	FClickSig ClickDel;
};