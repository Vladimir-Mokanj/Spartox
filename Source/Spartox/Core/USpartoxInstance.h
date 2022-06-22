// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Items/Structs/FItemStruct.h"
#include "USpartoxInstance.generated.h"

UCLASS(Blueprintable)
class SPARTOX_API UUSpartoxInstance final : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<FItemStruct> InventoryDatabase;
};
