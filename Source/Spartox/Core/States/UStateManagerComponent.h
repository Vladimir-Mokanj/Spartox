#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UStateBase.h"
#include "UStateManagerComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPARTOX_API UUStateManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UUStateManagerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "State Machine")
		FString InitialState;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "State Machine")
		TMap<FString, TSubclassOf<UUStateBase>> AvailableStates;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "State Machine Debug")
		bool bDebug = false;

	UPROPERTY(BlueprintReadOnly)
		TArray<UUStateBase*> StateHistory;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "State Machine Debug", meta = (ClampMin = "0", ClampMax = "10", UIMin = "0", UIMax = "10"))
		int32 StateHistoryLength;
	UPROPERTY(BlueprintReadOnly)
		UUStateBase* CurrentState = nullptr;

	UPROPERTY()
		TMap<FString, UUStateBase*> StateMap;

	UFUNCTION(BlueprintCallable, Category = "State Machine")
		void SwitchStateByKey(FString StateKey);
	UFUNCTION(BlueprintCallable, Category = "State Machine")
		void InitStateManager();

private:
	bool bCanTickState = false;
	void InitializeStates();
};