// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGGameInstance.h"
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
}

void URPGGameInstance::LoadMainMenu()
{
	
}

void URPGGameInstance::CheckSaveGames()
{
	
}

void URPGGameInstance::SaveGame(FString SaveName)
{
}
