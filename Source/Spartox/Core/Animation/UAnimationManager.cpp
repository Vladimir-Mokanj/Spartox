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

	// Check to see if animations are loaded
	if (Animations.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("Animations is an empty TMap: %s"), *GetOwner()->GetName())
	}
}

UAnimationAsset* UUAnimationManager::GetAnimationByKey(const FString& AnimationName) const
{
	// Check to see if animations are loaded
	if (Animations.IsEmpty())
	{
		UE_LOG(LogTemp, Error, TEXT("%s actor has an animation that is empty: %s"), *GetOwner()->GetName(), *AnimationName);
		return nullptr;
	}

	// Find animation by value
	UAnimationAsset* FindAnimation = Animations.FindRef(AnimationName);
	if (FindAnimation == nullptr)
		return nullptr;

	return FindAnimation;
}
