// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataManager.generated.h"

UCLASS()
class HUAWEIWALL_API ADataManager : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADataManager();
	UFUNCTION(BlueprintCallable, Category = "APILinkF")
	void LoadData();
	UFUNCTION(BlueprintPure, Category = "APILinkF")
	FString GetAPI(const FString& Key) const;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "APILink")
	TMap<FString, FString> APIMap;

	UPROPERTY(BlueprintReadOnly)
	int32 WindowWidth;

	UPROPERTY(BlueprintReadOnly)
	int32 WindowHeight;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
