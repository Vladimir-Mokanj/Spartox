// Project done by Vladimir Mokanj

#include "APlayerControllerBase.h"

void AAPlayerControllerBase::PressMove()
{
	UE_LOG(LogTemp, Log, TEXT("CLICKED"));

	if (MoveDelegate.IsBound())
	{
		MoveDelegate.Broadcast();
	}
}

void AAPlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	/*Bind Actions*/
	InputComponent->BindAction("MouseClick", EInputEvent::IE_Pressed, this, &AAPlayerControllerBase::PressMove);
}

FMoveSignature* AAPlayerControllerBase::GetMoveDelegate()
{
	return &MoveDelegate;
}