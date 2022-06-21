#include "UStateManagerComponent.h"

// Sets default values for this component's properties
UUStateManagerComponent::UUStateManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUStateManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	InitializeStates();

	// ...

}


// Called every frame
void UUStateManagerComponent::TickComponent(const float DeltaTime, const ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bCanTickState)
	{
		CurrentState->TickState(DeltaTime);
	}
	if (bDebug)
	{
		if (CurrentState)
			GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Green, this->GetOwner()->GetName() + "'s current state: " + CurrentState->StateDisplayName.GetPlainNameString());
		if (StateHistory.Num() > 0)
		{
			for (int32 i = 0; i < StateHistory.Num(); i++)
			{
				GEngine->AddOnScreenDebugMessage(-1, 0.0f, FColor::Purple, this->GetOwner()->GetName() + "'s past state " + FString::FromInt(i) + " " + StateHistory[i]->GetName());
			}
		}
	}
	// ...
}

void UUStateManagerComponent::SwitchStateByKey(FString StateKey)
{
	/*Bind the state*/
	UUStateBase* NewState = StateMap.FindRef(StateKey);

	if (NewState->IsValidLowLevel())
	{
		/*If there is no current state, it means we are at init*/
		if (!CurrentState)
		{
			CurrentState = NewState;
		}
		else
		{
			if (CurrentState->GetClass() == NewState->GetClass() && CurrentState->bCanRepeat == false)
			{
				if (bDebug)
				{
					GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, this->GetOwner()->GetName() + "'s state switch failed. " + CurrentState->StateDisplayName.GetPlainNameString() + " is not repeatable!", true);
				}
			}
			else
			{
				bCanTickState = false;

				CurrentState->ExitState();

				if (StateHistoryLength != 0)
				{
					if (StateHistory.Num() < StateHistoryLength)
					{
						StateHistory.Push(CurrentState);
					}
					else
					{
						StateHistory.RemoveAt(0);
						StateHistory.Push(CurrentState);
					}
				}

				CurrentState = NewState;
			}
		}

		if (CurrentState)
		{
			CurrentState->EnterState(GetOwner());
			bCanTickState = true;
		}
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, this->GetOwner()->GetName() + "'s state switch failed. " + "Invalid state!");
	}
}


void UUStateManagerComponent::InitStateManager()
{
	SwitchStateByKey(InitialState);
}

void UUStateManagerComponent::InitializeStates()
{
	/*Create State and hold them in memory for when needed*/
	for (auto It = AvailableStates.CreateConstIterator(); It; ++It)
	{
		UUStateBase* State = NewObject<UUStateBase>(this, It->Value);
		StateMap.Add(It->Key, State);
	}
}