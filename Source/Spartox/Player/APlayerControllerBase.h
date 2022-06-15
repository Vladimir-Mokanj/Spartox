// Project done by Vladimir Mokanj

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/IPlayerMove.h"
#include "GameFramework/PlayerController.h"
#include "APlayerControllerBase.generated.h"

UCLASS(Blueprintable)
class SPARTOX_API AAPlayerControllerBase : public APlayerController, public IIPlayerMove
{
	GENERATED_BODY()

public:
	AAPlayerControllerBase();

	/** Time Threshold to know if it was a short press */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		float ShortPressThreshold;

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
	virtual FMoveSignature* GetMoveDelegate() override;

private:
	bool bInputPressed; // Input is bring pressed
	float FollowTime; // For how long it has been pressed
	FMoveSignature MoveDelegate;
};