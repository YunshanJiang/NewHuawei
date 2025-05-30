// Fill out your copyright notice in the Description page of Project Settings.


#include "APIManager.h"
#include "HttpModule.h"
#include "Misc/Paths.h"
#include "Misc/FileHelper.h"
#include "HttpModule.h"
#include "Interfaces/IHttpRequest.h"
#include "Interfaces/IHttpResponse.h"
// Sets default values
AAPIManager::AAPIManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAPIManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAPIManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAPIManager::GetSentenceData()
{

    if (getDataLink.IsEmpty())
    {
        return;
    }
    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
    UE_LOG(LogTemp, Log, TEXT("getDataLink: %s"), *getDataLink);
    Request->SetURL(getDataLink);
    Request->SetVerb("GET");

    // 捕获this指针以便在lambda中访问成员函数
    Request->OnProcessRequestComplete().BindLambda([this](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
        {
            if (bWasSuccessful && Response.IsValid())
            {
                UE_LOG(LogTemp, Log, TEXT("API Response: %s"), *Response->GetContentAsString());
                FString JsonContent = Response->GetContentAsString();
                this->LoadJsonData(JsonContent);
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("API Request failed"));
            }
        });
    Request->ProcessRequest();
}

void AAPIManager::PostIDData()
{
    if (postDataLink.IsEmpty())
    {
        return;
    }
    if (IdArray.Num() == 0)
    {
        return;
    }
    FString tempID = "";
    tempID = IdArray[0]; // Get the first ID from the array
    IdArray.RemoveAt(0);
    
    TSharedRef<IHttpRequest, ESPMode::ThreadSafe> Request = FHttpModule::Get().CreateRequest();
    Request->SetURL(postDataLink + tempID);
    Request->SetVerb("POST");
    Request->SetHeader(TEXT("Content-Type"), TEXT("application/json"));
    Request->SetContentAsString(TEXT("")); // Empty body
    Request->OnProcessRequestComplete().BindLambda([](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
        {
            if (bWasSuccessful && Response.IsValid())
            {
                UE_LOG(LogTemp, Log, TEXT("Response: %s"), *Response->GetContentAsString());
            }
            else
            {
                UE_LOG(LogTemp, Error, TEXT("Request failed"));
            }
        });
    Request->ProcessRequest();


}

void AAPIManager::LoadJsonData(FString& JsonContent)
{
    TSharedRef<TJsonReader<>> JsonReader = TJsonReaderFactory<>::Create(JsonContent);
    TArray<TSharedPtr<FJsonValue>> JsonArray;

    if (FJsonSerializer::Deserialize(JsonReader, JsonArray))
    {
        for (const TSharedPtr<FJsonValue>& Value : JsonArray)
        {
            if (Value.IsValid() && Value->Type == EJson::Object)
            {
                TSharedPtr<FJsonObject> JsonObject = Value->AsObject();
                if (JsonObject.IsValid())
                {
                    FString Id = JsonObject->GetStringField("id");
                    FString Path = JsonObject->GetStringField("path");

                    IdArray.Add(Id);
                    PathArray.Add(Path);
                }
            }
        }

        // Optional: Log the results
        for (int32 i = 0; i < IdArray.Num(); ++i)
        {
            UE_LOG(LogTemp, Log, TEXT("Entry %d: ID = %s, Path = %s"), i, *IdArray[i], *PathArray[i]);
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to deserialize JSON array."));
    }
}
