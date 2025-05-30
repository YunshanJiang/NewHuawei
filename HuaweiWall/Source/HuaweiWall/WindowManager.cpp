// Fill out your copyright notice in the Description page of Project Settings.


#include "WindowManager.h"
#include "Windows/AllowWindowsPlatformTypes.h"
#include <Windows.h>
#include "Windows/HideWindowsPlatformTypes.h"
// Sets default values
AWindowManager::AWindowManager()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWindowManager::BeginPlay()
{
    Super::BeginPlay();

}


// Called every frame
void AWindowManager::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}



void AWindowManager::SetWindowAlwaysOnTop()
{
    HWND hWnd = GetActiveWindow();
    if (hWnd)
    {
       
        LONG Style = GetWindowLong(hWnd, GWL_STYLE);
        Style &= ~(WS_BORDER | WS_DLGFRAME | WS_THICKFRAME);
        Style |= WS_POPUP;
        SetWindowLong(hWnd, GWL_STYLE, Style);
        SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, WindowWidth, WindowHeight, SWP_FRAMECHANGED | SWP_NOOWNERZORDER | SWP_SHOWWINDOW);
        UE_LOG(LogTemp, Log, TEXT("Window set to topmost."));
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to retrieve active window handle."));
    }
}

void AWindowManager::CheckWindowCondition()
{
     
    HWND hWnd = GetActiveWindow();
    if (hWnd)
    {
        RECT windowRect;
        if (GetWindowRect(hWnd, &windowRect))
        {
            int32 windowLeft = windowRect.left;
            int32 windowTop = windowRect.top;

            if (windowLeft != 0 || windowTop != 0)
            {
               
                LONG Style = GetWindowLong(hWnd, GWL_STYLE);
                Style &= ~(WS_BORDER | WS_DLGFRAME | WS_THICKFRAME);
                Style |= WS_POPUP;
                SetWindowLong(hWnd, GWL_STYLE, Style);
                SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, WindowWidth, WindowHeight, SWP_FRAMECHANGED | SWP_NOOWNERZORDER | SWP_SHOWWINDOW);
                UE_LOG(LogTemp, Log, TEXT("Window set to topmost."));

            }
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to retrieve active window handle."));
    }
}
