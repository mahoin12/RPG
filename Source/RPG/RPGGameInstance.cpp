// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGGameInstance.h"
#include "RPGSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Logging/LogMacros.h"

URPGGameInstance::URPGGameInstance(const FObjectInitializer& ObjectInitializer)
{
	
}

void URPGGameInstance::CheckSaveGames()
{
	if(UGameplayStatics::DoesSaveGameExist("Slot1",0))
	{
		URPGSaveGame* Slot1 = Cast<URPGSaveGame>(UGameplayStatics::LoadGameFromSlot("Slot1",0));
		if(Slot1)
		{
			
		}
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

void URPGGameInstance::SaveGame(FString SaveName, FString SlotName)
{
	URPGSaveGame* SavedGame;
	if(UGameplayStatics::DoesSaveGameExist("SlotName",0))
		SavedGame = Cast<URPGSaveGame>(UGameplayStatics::LoadGameFromSlot("SlotName",0));
	else
		SavedGame = Cast<URPGSaveGame>(UGameplayStatics::CreateSaveGameObject(URPGSaveGame::StaticClass()));
	if(SavedGame)
	{
		SavedGame->SetCharacterStats(RPGCharacterStats);
		SavedGame->SetSaveGameName(SaveName);
	}
}

