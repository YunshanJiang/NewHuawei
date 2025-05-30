// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FSMManager.h" // Include FSMManager class to hold a reference
#include "BaseState.generated.h"

UCLASS()
class HUAWEIWALL_API ABaseState : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseState();
	UPROPERTY(BlueprintReadWrite, Category = "FSM")
	AFSMManager* FSMManager;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
