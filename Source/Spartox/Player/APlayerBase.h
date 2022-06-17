// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Spartox/Core/States/UStateManagerComponent.h"
#include "APlayerBase.generated.h"

UCLASS(Blueprintable)
class SPARTOX_API AAPlayerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Variables
	FHitResult HitResult;

	// Sets default values for this character's properties
	AAPlayerBase();

	UPROPERTY(BlueprintReadOnly)
		bool bIsMoving = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UUStateManagerComponent* StateManager;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TMap<FString, UAnimationAsset*> Animations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MoveDistanceRange;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};