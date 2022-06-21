// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IPlayerClickInteract.generated.h"

// This class does not need to be modified.
DECLARE_MULTICAST_DELEGATE(FClickSig)

UINTERFACE(MinimalAPI)
class UIPlayerClickInteract : public UInterface
{
	GENERATED_BODY()
};

class SPARTOX_API IIPlayerClickInteract
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FClickSig* GetClickDel() = 0;
};
