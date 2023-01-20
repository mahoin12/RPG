// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGGameInstance.h"
#include "RPGPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Logging/LogMacros.h"
#include "UI/WB_Escape.h"
#include "UI/WB_MainMenu.h"

URPGGameInstance::URPGGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UWB_MainMenu> WB_MainMenu(TEXT("/Game/UI/WB_MainMenu"));
	if (!ensure(WB_MainMenu.Class != nullptr)) return;
	MainMenuClass =WB_MainMenu.Class;
	
	ConstructorHelpers::FClassFinder<UWB_Escape> WB_Escape(TEXT("/Game/UI/WB_Escape"));
	if (!ensure(WB_Escape.Class != nullptr)) return;
	EscapeMenuClass =WB_Escape.Class;
}

void URPGGameInstance::CreateEscapeMenu()
{
	UE_LOG(LogTemp,Warning,TEXT("escapemenu"))
	EscapeMenu = CreateWidget<UWB_Escape>(GetWorld(),EscapeMenuClass);
	if (!ensure(EscapeMenu != nullptr)) return;
	EscapeMenu->AddToViewport(0);
	EscapeMenu->Setup(this);

	// Getting player controller
	ARPGPlayerController* PlayerController = Cast<ARPGPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(),0));
	// Check for player controller
	if (PlayerController)
	{
		// Setting parameters
		FInputModeUIOnly InputModeData;
		InputModeData.SetWidgetToFocus(EscapeMenu->TakeWidget());
		InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		PlayerController->SetInputMode(InputModeData);
		PlayerController->SetShowMouseCursor(true);
		PlayerController->SetPause(true);
	}
}

void URPGGameInstance::CreateMenu()
{
	MainMenu = CreateWidget<UWB_MainMenu>(GetWorld(),MainMenuClass);
	if (!ensure(MainMenu != nullptr)) return;
	MainMenu->AddToViewport(0);
	MainMenu->Setup(this);

	// Getting player controller
	ARPGPlayerController* PlayerController = Cast<ARPGPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(),0));
	// Check for player controller
	if (PlayerController)
	{
		// Setting parameters
		FInputModeUIOnly InputModeData;
		InputModeData.SetWidgetToFocus(MainMenu->TakeWidget());
		InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		PlayerController->SetInputMode(InputModeData);
		PlayerController->SetShowMouseCursor(true);
	}
}

void URPGGameInstance::LoadMainMenu()
{
	
}

void URPGGameInstance::Quit()
{
	UKismetSystemLibrary::QuitGame(GetWorld(),0,EQuitPreference::Quit,false);
}

void URPGGameInstance::CheckSaveGames()
{
	if(UGameplayStatics::DoesSaveGameExist("Slot1",0))
	{
		
	}
	if(UGameplayStatics::DoesSaveGameExist("Slot2",0))
	{
		
	}
	if(UGameplayStatics::DoesSaveGameExist("Slot3",0))
	{
		
	}
	if(UGameplayStatics::DoesSaveGameExist("Slot4",0))
	{
		
	}
}

void URPGGameInstance::SaveGame(FString SaveName)
{
	
}

void URPGGameInstance::NewGame()
{
	UGameplayStatics::OpenLevel(GetWorld(),"StartLevel",true);
	
	// Getting player controller
	ARPGPlayerController* PlayerController = Cast<ARPGPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(),0));
	// Check for player controller
	if(PlayerController)
	{
		// Setting parameters
		FInputModeGameOnly InputModeData;
		PlayerController->SetInputMode(InputModeData);
		PlayerController->SetShowMouseCursor(false);
	}
}

void URPGGameInstance::BackToGame()
{
	EscapeMenu->RemoveFromParent();
	// Getting player controller
	ARPGPlayerController* PlayerController = Cast<ARPGPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(),0));
	// Check for player controller
	if(PlayerController)
	{
		// Setting parameters
		FInputModeGameOnly InputModeData;
		PlayerController->SetInputMode(InputModeData);
		PlayerController->SetShowMouseCursor(false);
		PlayerController->SetPause(false);
	}
}

void URPGGameInstance::ToMainMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(),"MainMenu",true);
	//CreateMenu();
}

