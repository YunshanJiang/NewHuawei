// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataManager.h"
#include "WindowManager.h"
#include "APIManager.h"
#include "FSMManager.h"
#include "GameManager.generated.h"

UCLASS()
class HUAWEIWALL_API AGameManager : public AActor
{
	GENERATED_BODY()


public:
	// Sets default values for this actor's properties
	AGameManager();
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manager")
	//ADataManager* DataManager;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manager")
	//AWindowManager* WindowManager;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manager")
	//AAPIManager* APIManager;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Manager")
	//AFSMManager* FSMManager;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
