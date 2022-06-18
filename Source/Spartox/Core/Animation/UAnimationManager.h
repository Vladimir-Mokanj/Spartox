// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UAnimationManager.generated.h"


UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPARTOX_API UUAnimationManager final : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUAnimationManager();

	// Animations that are used in the game
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<FString, UAnimationAsset*> Animations;

	// Returns the pointer to animation asset that is mapped in TMap Animations.
	UFUNCTION(BlueprintCallable)
		UAnimationAsset* GetAnimationByKey(const FString& AnimationName) const;

protected:
	virtual void BeginPlay() override;
};
