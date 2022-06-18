// Project done by Vladimir Mokanj

#include "APlayerBase.h"

#include "Spartox/Core/Animation/UAnimationManager.h"

// Sets default values
AAPlayerBase::AAPlayerBase()
{
	PrimaryActorTick.bCanEverTick = false;

	StateManager = CreateDefaultSubobject<UUStateManagerComponent>(TEXT("StateManager"));		// Holds FSM
	AnimationManager = CreateDefaultSubobject<UUAnimationManager>(TEXT("AnimationManager"));	// Holds animations
}

void AAPlayerBase::BeginPlay()
{
	Super::BeginPlay();

	StateManager->InitStateManager();
}