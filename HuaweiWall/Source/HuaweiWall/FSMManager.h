// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FSMManager.generated.h"


UENUM(BlueprintType)
enum class EGameState : uint8
{
	Intro,
	Interaction,
	Ending
};



UCLASS()
class HUAWEIWALL_API AFSMManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFSMManager();
	UPROPERTY(BlueprintReadWrite)
	EGameState CurrentState;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Function to transition to the next state
	//UFUNCTION(BlueprintCallable, Category = "FSM")
	//void StateDone();

	// Function to transition to a specific state
//	UFUNCTION(BlueprintCallable, Category = "FSM")
	//void SetState(EGameState NewState);

	// Optionally, expose the current state for Blueprint
	//UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FSM")
	//EGameState GetCurrentState() const { return CurrentState; }

	//UFUNCTION(BlueprintCallable, BlueprintPure, Category = "FSM")
	//ABaseState* GetCurrentStateActor() const { return CurrentStateActor; }

private:

	// Reference to the current state actor
	//ABaseState* CurrentStateActor;

	// Create a new state actor based on the current state
	//void CreateStateActor(EGameState NewState);

	// Destroy the current state actor
	//void DestroyCurrentStateActor();
};
