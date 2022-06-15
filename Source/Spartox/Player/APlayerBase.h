// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "APlayerBase.generated.h"

UCLASS(Blueprintable)
class SPARTOX_API AAPlayerBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAPlayerBase();

	// Called every frame
	virtual void Tick(const float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};