// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionState.h"
#include "Math/UnrealMathUtility.h"
// Sets default values
AInteractionState::AInteractionState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int AInteractionState::CheckIdIsShowing(int32 ID)
{
	int trackedIndex = -1;
	// Iterate through the UITextToggleTrackArray to check if the showerTextIDArray is present
	for (const int32& index : showerTextIDArray)
	{
		trackedIndex++;
		if (index == ID)
		{
			// The ID is showing, you can perform your logic here
			//UE_LOG(LogTemp, Log, TEXT("ID %d is currently showing."), showerTextIDArray);
			return trackedIndex;
		}
		
	}
	// If we reach here, the ID is not showing
	//UE_LOG(LogTemp, Log, TEXT("ID %d is not showing."), showerTextIDArray);
	return -1;
}

void AInteractionState::InitUITextToggleTrackArray(int32 count)
{
	UITextToggleTrackArray.SetNum(count);
	for (FUIIndexArrayOutSide& index : UITextToggleTrackArray)
	{
		index.UIIndexArrayInside.SetNum(2);
		
		for (int32& Cell : index.UIIndexArrayInside)
		{
			Cell = 1;
		}
	}
}

int32 AInteractionState::getRandomUnuseSeat(TArray<bool> animateArray)
{
	TArray<int> tempArray;
	int arrayIndex = 0;
	for (bool& index : animateArray)
	{
		if (!index)
		{
			tempArray.Add(arrayIndex);
		}
		arrayIndex++;
	}
	int32 RandomInt = FMath::RandRange(0, tempArray.Num()-1);
	return tempArray[RandomInt];
}

// Called when the game starts or when spawned
void AInteractionState::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractionState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

