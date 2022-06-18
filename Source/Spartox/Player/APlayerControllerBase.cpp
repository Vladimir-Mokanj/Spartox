// Project done by Vladimir Mokanj

#include "APlayerControllerBase.h"

void AAPlayerControllerBase::MouseClick()
{
	if (ClickDel.IsBound())
	{
		ClickDel.Broadcast();
	}
}

void AAPlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	//Bind Actions
	InputComponent->BindAction("MouseClick", EInputEvent::IE_Pressed, this, &AAPlayerControllerBase::MouseClick);
}

FMoveSignature* AAPlayerControllerBase::GetClickDel()
{
	return &ClickDel;
}