// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGGameInstance.h"
#include "RPGPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "UI/WB_MainMenu.h"

URPGGameInstance::URPGGameInstance(const FObjectInitializer& ObjectInitializer)
{
	
}

void URPGGameInstance::CreateMenu()
{
	ConstructorHelpers::FClassFinder<UWB_MainMenu> WB_MainMenu(TEXT("/Game/UI/WB_MainMenu"));
	if (!ensure(WB_MainMenu.Class != nullptr)) return;

	MainMenu = CreateWidget<UWB_MainMenu>(GetWorld(),WB_MainMenu.Class);
	if (!ensure(MainMenu != nullptr)) return;
	MainMenu->Setup();
	MainMenu->SetMenuInterface(this);
	ARPGPlayerController* PlayerController = Cast<ARPGPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(),0));
	if(PlayerController) PlayerController->SetShowMouseCursor(true);
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
