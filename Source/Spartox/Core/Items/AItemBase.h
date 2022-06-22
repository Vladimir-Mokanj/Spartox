// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AItemBase.generated.h"

UCLASS()
class SPARTOX_API AAItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
