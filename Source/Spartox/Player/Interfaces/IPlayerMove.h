// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IPlayerMove.generated.h"

// This class does not need to be modified.
DECLARE_MULTICAST_DELEGATE(FMoveSignature);

UINTERFACE(MinimalAPI)
class UIPlayerMove : public UInterface
{
	GENERATED_BODY()
};

class SPARTOX_API IIPlayerMove
{
	GENERATED_BODY()

		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual FMoveSignature* GetMoveDelegate() = 0;
};