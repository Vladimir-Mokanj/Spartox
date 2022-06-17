// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UAnimationManager.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPARTOX_API UUAnimationManager final : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUAnimationManager();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<FString, UAnimationAsset*> Animations;

	UPROPERTY(BlueprintReadOnly)
		UAnimationAsset* CurrentAnimation = nullptr;

protected:
	virtual void BeginPlay() override;
};
