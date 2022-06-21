// Project done by Vladimir Mokanj

#include "APlayerBase.h"

// Sets default values
AAPlayerBase::AAPlayerBase()
{
	PrimaryActorTick.bCanEverTick = false;

	StateManager = CreateDefaultSubobject<UUStateManagerComponent>(TEXT("StateManager"));		// Holds FSM
}

void AAPlayerBase::BeginPlay()
{
	Super::BeginPlay();

	StateManager->InitStateManager();
}