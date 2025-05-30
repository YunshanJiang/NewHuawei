// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Misc/Paths.h"
#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"
#include "APIManager.generated.h"

UCLASS()
class HUAWEIWALL_API AAPIManager : public AActor
{
	GENERATED_BODY()

public:
	// Expose the API URL to Blueprints
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HTTP")
	TArray<FString> IdArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HTTP")
	TArray<FString> PathArray;



	// Expose the API URL to Blueprints
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HTTP")
	FString getDataLink;

	// Expose the API URL to Blueprints
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HTTP")
	FString postDataLink;


	// Sets default values for this actor's properties
	AAPIManager();
	UFUNCTION(BlueprintCallable, Category = "HTTP")
	void GetSentenceData();

	void LoadJsonData(FString& JsonContent);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
