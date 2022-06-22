// Project done by Vladimir Mokanj

#include "AItemBase.h"

// Sets default values
AAItemBase::AAItemBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAItemBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

