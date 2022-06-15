#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UStateBase.h"
#include "UStateManagerComponent.generated.h"


UCLASS(Blueprintable, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SPARTOX_API UUStateManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UUStateManagerComponent();

	// Called every frame
	virtual void TickComponent(const float DeltaTime, const ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "State Machine")
		FString InitialState;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "State Machine")
		TMap<FString, TSubclassOf<UUStateBase>> AvailableStates;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "State Machine Debug")
		bool bDebugMode = false;

	UPROPERTY(BlueprintReadOnly)
		TArray<UUStateBase*> StateHistory;
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "State Machine", meta = (ClampMin = "0", ClampMax = "10", UIMin = "0", UIMax = "10"))
		int32 StateHistoryLength;
	UPROPERTY(BlueprintReadOnly)
		UUStateBase* CurrentState = nullptr;

	UPROPERTY()
		TMap<FString, UUStateBase*> StateMap;

	UFUNCTION(BlueprintCallable, Category = "State Machine")
		void SwitchStateByKey(FString StateKey);
	UFUNCTION(BlueprintCallable, Category = "State Machine")
		void SwitchState(UUStateBase* NewState);
	UFUNCTION(BlueprintCallable, Category = "State Machine")
		void InitStateManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	bool bCanTickState = false;

	void InitializeStates();
};