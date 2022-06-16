// Project done by Vladimir Mokanj

#include "UPlayerBaseState.h"
#include "Kismet/GameplayStatics.h"

void UUPlayerBaseState::EnterState(AActor* OwnerRef)
{
	Super::EnterState(OwnerRef);

	//Save player ref for later
	if (!PlayerRef)
	{
		PlayerRef = Cast<AAPlayerBase>(OwnerRef);
	}

	/*Save the play er controller*/
	if (!PlayerController)
	{
		PlayerController = Cast<IIPlayerMove>(UGameplayStatics::GetPlayerController(this, 0));
	}
	/*Bind Jump Delegate*/

	if (PlayerController)
	{
		PlayerController->GetMoveDelegate()->AddUObject(this, &UUPlayerBaseState::ClickMove);
	}
}

void UUPlayerBaseState::ExitState()
{
	Super::ExitState();
	/*Remove JUmp delegate*/
	PlayerController->GetMoveDelegate()->RemoveAll(this);
}

void UUPlayerBaseState::ClickMove()
{

}
