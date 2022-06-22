// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "EItemType.generated.h"

UENUM(BlueprintType)
enum EItemType
{
    Weapon      UMETA(DisplayName = "Weapon"),
    Resource    UMETA(DisplayName = "Resource"),
    Consumable  UMETA(DisplayName = "Consumable"),
};
