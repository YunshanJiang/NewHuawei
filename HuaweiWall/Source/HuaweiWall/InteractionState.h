// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseState.h"
#include "InteractionState.generated.h"


USTRUCT(BlueprintType)
struct FUIIndexArrayOutSide
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveV")
	TArray<int32> UIIndexArrayInside;


};


UCLASS()
class HUAWEIWALL_API AInteractionState : public ABaseState
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractionState();
	// Expose the API URL to Blueprints
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveV")
	TArray<int32> showerTextIDArray;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InteractiveV")
	TArray<FUIIndexArrayOutSide> UITextToggleTrackArray;

	UFUNCTION(BlueprintCallable, Category = "InteractiveV")
	int CheckIdIsShowing(int32 ID);
	UFUNCTION(BlueprintCallable, Category = "InteractiveV")
	void InitUITextToggleTrackArray(int32 count);
	UFUNCTION(BlueprintCallable, Category = "InteractiveV")
	int getRandomUnuseSeat(TArray<bool> animateArray);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
