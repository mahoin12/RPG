// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGGameInstance.h"
#include "RPGSaveGame.h"
#include "Kismet/GameplayStatics.h"
#include "Logging/LogMacros.h"
#include "UI/Menu/MenuBase.h"

URPGGameInstance::URPGGameInstance(const FObjectInitializer& ObjectInitializer)
{
	
}

void URPGGameInstance::CheckSaveGames(UMenuBase* Menu)
{
	if(UGameplayStatics::DoesSaveGameExist("Slot1",0))
	{
		URPGSaveGame* Slot1 = Cast<URPGSaveGame>(UGameplayStatics::LoadGameFromSlot("Slot1",0));
		if(Slot1)
		{
			Menu->SetSlotName(1,Slot1->GetSaveGameName());
			UE_LOG(LogTemp,Warning,TEXT("%s"),*Slot1->GetSaveGameName())
		}
	}
	if(UGameplayStatics::DoesSaveGameExist("Slot2",0))
	{
		URPGSaveGame* Slot2 = Cast<URPGSaveGame>(UGameplayStatics::LoadGameFromSlot("Slot2",0));
		if(Slot2)
		{
			Menu->SetSlotName(1,Slot2->GetSaveGameName());
		}
	}
	if(UGameplayStatics::DoesSaveGameExist("Slot3",0))
	{
		URPGSaveGame* Slot3 = Cast<URPGSaveGame>(UGameplayStatics::LoadGameFromSlot("Slot3",0));
		if(Slot3)
		{
			Menu->SetSlotName(1,Slot3->GetSaveGameName());
		}
	}
	if(UGameplayStatics::DoesSaveGameExist("Slot4",0))
	{
		URPGSaveGame* Slot4 = Cast<URPGSaveGame>(UGameplayStatics::LoadGameFromSlot("Slot4",0));
		if(Slot4)
		{
			Menu->SetSlotName(1,Slot4->GetSaveGameName());
		}
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

