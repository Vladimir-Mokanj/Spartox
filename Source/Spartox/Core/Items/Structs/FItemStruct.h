// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Spartox/Core/Items/Enumerators/EItemRarity.h"
#include "Spartox/Core/Items/Enumerators/EItemType.h"
#include "FItemStruct.generated.h"

USTRUCT(BlueprintType)
struct FItemStruct : public FTableRowBase
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FString Description;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EItemType> Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UTexture2D* Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMesh* Model;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EItemRarity> Rarity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 Quantity;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bStackable;
};
