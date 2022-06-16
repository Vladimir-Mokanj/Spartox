// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UStateBase.generated.h"

UCLASS()
class SPARTOX_API UUStateBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		bool bCanTickState = false;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		bool bCanRepeat = false;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
		FName StateDisplayName;

	virtual void EnterState(AActor* StateOwner);
	virtual void TickState(const float DeltaTime);
	virtual void ExitState();
};