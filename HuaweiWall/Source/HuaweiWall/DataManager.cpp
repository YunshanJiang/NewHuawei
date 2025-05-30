// Fill out your copyright notice in the Description page of Project Settings.


#include "DataManager.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Json.h"
#include "JsonUtilities.h"
// Sets default values
ADataManager::ADataManager()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADataManager::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void ADataManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    FString ApiValue = GetAPI("get_user");
   // UE_LOG(LogTemp, Log, TEXT("API 'get_user': %s"), *ApiValue);
}

void ADataManager::LoadData()
{
    FString DataPath = FPaths::ProjectDir() / TEXT("data/api.txt");
    FString CommonPath = FPaths::ProjectDir() / TEXT("data/common.txt");
    FString FileContent;
    
    // Load API map
    if (FFileHelper::LoadFileToString(FileContent, *DataPath))
    {

        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(FileContent);

        if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
        {
            UE_LOG(LogTemp, Log, TEXT("rt: %hs"), "test2");
            for (const auto& Pair : JsonObject->Values)
            {
                FString Key = Pair.Key;
                FString Value;
                if (Pair.Value->TryGetString(Value))
                {
                    APIMap.Add(Key, Value);
                }
            }
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to load file: %s"), *DataPath);
    }
    // Load window settings
    if (FFileHelper::LoadFileToString(FileContent, *CommonPath))
    {
        UE_LOG(LogTemp, Log, TEXT("rt: %s"), *CommonPath);
        TSharedPtr<FJsonObject> JsonObject;
        TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(FileContent);

        if (FJsonSerializer::Deserialize(Reader, JsonObject) && JsonObject.IsValid())
        {
            WindowWidth = JsonObject->GetIntegerField("width");
            WindowHeight = JsonObject->GetIntegerField("height");
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to load file: %s"), *CommonPath);
    }
}
FString ADataManager::GetAPI(const FString& Key) const
{
    const FString* Found = APIMap.Find(Key);
    return Found ? *Found : FString("");
}
