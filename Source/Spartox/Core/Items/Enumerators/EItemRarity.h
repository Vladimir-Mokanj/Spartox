// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "EItemRarity.generated.h"

UENUM(BlueprintType)
enum EItemRarity
{
    Common      UMETA(DisplayName = "Common"),
    Uncommon    UMETA(DisplayName = "Uncommon"),
    Rare        UMETA(DisplayName = "Rare"),
	Epic        UMETA(DisplayName = "Epic"),
	Legendary   UMETA(DisplayName = "Legendary"),
};
