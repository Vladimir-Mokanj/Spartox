// Project done by Vladimir Mokanj


#include "UAnimationManager.h"

// Sets default values for this component's properties
UUAnimationManager::UUAnimationManager()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UUAnimationManager::BeginPlay()
{
	Super::BeginPlay();

	if (Animations.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Animations is empty: %s"), *GetOwner()->GetName())
	}
}