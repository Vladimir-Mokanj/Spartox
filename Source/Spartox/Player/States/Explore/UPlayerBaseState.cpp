// Project done by Vladimir Mokanj

#include "UPlayerBaseState.h"

#include "Spartox/Player/APlayerBase.h"
#include "Kismet/GameplayStatics.h"
#include "Spartox/Player/Interfaces/IPlayerMove.h"

void UUPlayerBaseState::EnterState(AActor* StateOwner)
{
	Super::EnterState(StateOwner);

	if (PlayerRef == nullptr)
	{
		PlayerRef = Cast<AAPlayerBase>(PlayerRef);
	}

	if (PlayerControllerIfc == nullptr)
	{
		PlayerControllerIfc = Cast<IIPlayerMove>(UGameplayStatics::GetPlayerController(this, 0));
	}

	if (PlayerControllerIfc != nullptr)
	{
		PlayerControllerIfc->GetMoveDelegate()->AddUObject(this, &UUPlayerBaseState::ClickMove);
	}
}

void UUPlayerBaseState::ExitState()
{
	PlayerControllerIfc->GetMoveDelegate()->RemoveAll(this);
}

void UUPlayerBaseState::ClickMove()
{
}