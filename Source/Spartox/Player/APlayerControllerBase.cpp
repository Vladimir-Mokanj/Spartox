// Project done by Vladimir Mokanj

#include "APlayerControllerBase.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"

AAPlayerControllerBase::AAPlayerControllerBase()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
}

void AAPlayerControllerBase::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (bInputPressed)
	{
		FollowTime += DeltaTime;

		// Look for the touch location
		FVector HitLocation = FVector::ZeroVector;
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, true, Hit);

		HitLocation = Hit.Location;

		// Direct the Pawn towards that location
		APawn* const MyPawn = GetPawn();
		if (MyPawn)
		{
			FVector WorldDirection = (HitLocation - MyPawn->GetActorLocation()).GetSafeNormal();
			MyPawn->AddMovementInput(WorldDirection, 1.f, false);
		}
	}
	else
	{
		FollowTime = 0.f;
	}
}

void AAPlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("MouseClick", IE_Pressed, this, &AAPlayerControllerBase::OnSetDestinationPressed);
	InputComponent->BindAction("MouseClick", IE_Released, this, &AAPlayerControllerBase::OnSetDestinationReleased);
}

void AAPlayerControllerBase::OnSetDestinationPressed()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Pressed"));

	if (MoveDelegate.IsBound() == true)
	{
		MoveDelegate.Broadcast();
	}
	// We flag that the input is being pressed
	//bInputPressed = true;
	// Just in case the character was moving because of a previous short press we stop it
	//StopMovement();
}

void AAPlayerControllerBase::OnSetDestinationReleased()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("Released"));
	// Player is no longer pressing the input
	bInputPressed = false;

	// If it was a short press
	if (FollowTime <= ShortPressThreshold)
	{
		// We look for the location in the world where the player has pressed the input
		FVector HitLocation = FVector::ZeroVector;
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, true, Hit);
		HitLocation = Hit.Location;

		// We move there and spawn some particles
		//UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, HitLocation);
	}
}

FMoveSignature* AAPlayerControllerBase::GetMoveDelegate()
{
	return &MoveDelegate;
}