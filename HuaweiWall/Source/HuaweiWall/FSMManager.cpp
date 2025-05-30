// Fill out your copyright notice in the Description page of Project Settings.


#include "FSMManager.h"

// Sets default values
AFSMManager::AFSMManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFSMManager::BeginPlay()
{
	Super::BeginPlay();
	CurrentState = EGameState::Intro;
}

// Called every frame
void AFSMManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
/*
void AFSMManager::SetState(EGameState NewState)
{
    // Destroy the current state actor if it's active
    DestroyCurrentStateActor();

    // Create the new state actor
    CreateStateActor(NewState);
}

void AFSMManager::StateDone()
{
    // Move to the next state
    switch (CurrentState)
    {
    case EGameState::Intro:
        SetState(EGameState::Interaction);
        break;
    case EGameState::Interaction:
        SetState(EGameState::Ending);
        break;
    case EGameState::Ending:
        SetState(EGameState::Intro);  // Loop back to Intro for now
        break;
    }
}

void AFSMManager::CreateStateActor(EGameState NewState)
{
    CurrentState = NewState;

    // You can spawn different state actors based on the state
    switch (CurrentState)
    {
    case EGameState::Intro:
        CurrentStateActor = GetWorld()->SpawnActor<AStateActor>(AStateActor::StaticClass());
        break;

    case EGameState::Interaction:
        CurrentStateActor = GetWorld()->SpawnActor<AStateActor>(AStateActor::StaticClass());
        break;

    case EGameState::Ending:
        CurrentStateActor = GetWorld()->SpawnActor<AStateActor>(AStateActor::StaticClass());
        break;
    }

    if (CurrentStateActor)
    {
        CurrentStateActor->EnterState();
    }
}

void AFSMManager::DestroyCurrentStateActor()
{
    if (CurrentStateActor)
    {
        CurrentStateActor->Destroy();
        CurrentStateActor = nullptr;
    }
}*/