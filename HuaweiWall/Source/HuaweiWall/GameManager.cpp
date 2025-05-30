// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"
#include "EngineUtils.h" // Add this include at the top of your file
// Sets default values
AGameManager::AGameManager()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();
    if (World)
    {
        // DataManager = World->SpawnActor<ADataManager>();
       //  WindowManager = World->SpawnActor<AWindowManager>();
       //  APIManager = World->SpawnActor<AAPIManager>();
       //  FSMManager = World->SpawnActor<AFSMManager>();

        // if (DataManager) DataManager->LoadData();
        // if (WindowManager) WindowManager->Init();
       //  if (FSMManager) FSMManager->Init();
    }
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}



