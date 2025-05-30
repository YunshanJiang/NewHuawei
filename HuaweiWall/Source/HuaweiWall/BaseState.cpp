// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseState.h"
#include "Kismet/GameplayStatics.h"  // Required for GetActorOfClass
// Sets default values
ABaseState::ABaseState()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseState::BeginPlay()
{
	Super::BeginPlay();
    FSMManager = Cast<AFSMManager>(UGameplayStatics::GetActorOfClass(GetWorld(), AFSMManager::StaticClass()));

    if (FSMManager)
    {
        UE_LOG(LogTemp, Warning, TEXT("FSMManager found in the scene!"));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("FSMManager not found in the scene!"));
    }
	
}

// Called every frame
void ABaseState::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

