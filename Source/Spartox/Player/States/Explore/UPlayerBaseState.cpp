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

	// Save the Player Controller
	if (!PlayerController)
	{
		PlayerController = Cast<IIPlayerClickInteract>(UGameplayStatics::GetPlayerController(this, 0));
	}


	if (PlayerController)
	{
		PlayerController->GetClickDel()->AddUObject(this, &UUPlayerBaseState::MouseClick);
	}
}

void UUPlayerBaseState::ExitState()
{
	Super::ExitState();

	// Remove move delegate
	PlayerController->GetClickDel()->RemoveAll(this);
}

void UUPlayerBaseState::MouseClick()
{

}
