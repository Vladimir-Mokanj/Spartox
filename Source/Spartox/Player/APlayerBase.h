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
	// Sets default values for this character's properties
	AAPlayerBase();

	// Variables
	FHitResult HitResult;

	// This will be moved later.
	UPROPERTY(VisibleAnywhere)
		bool bIsMoving = false;

	// This will be moved later.
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MoveDistanceRange;

	// Holds the state manager reference (holds FSM)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UUStateManagerComponent* StateManager;

	// Holds the animation manager reference (holds animations for the object)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UUAnimationManager* AnimationManager;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};