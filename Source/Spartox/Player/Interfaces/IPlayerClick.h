// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IPlayerClick.generated.h"

DECLARE_MULTICAST_DELEGATE(FCickSign);

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIPlayerClick : public UInterface
{
	GENERATED_BODY()
};

class SPARTOX_API IIPlayerClick
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FCickSign* GetClickDelegate() = 0;
};
