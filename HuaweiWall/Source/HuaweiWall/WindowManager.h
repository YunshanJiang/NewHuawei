// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WindowManager.generated.h"

UCLASS()
class HUAWEIWALL_API AWindowManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWindowManager();
	UPROPERTY(BlueprintReadWrite)
	int32 WindowWidth;

	UPROPERTY(BlueprintReadWrite)
	int32 WindowHeight;

	UFUNCTION(BlueprintCallable, Category = "WindowF")
	void SetWindowAlwaysOnTop();
	UFUNCTION(BlueprintCallable, Category = "WindowF")
	void CheckWindowCondition();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
