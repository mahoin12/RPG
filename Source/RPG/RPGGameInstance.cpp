// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Logging/LogMacros.h"

URPGGameInstance::URPGGameInstance(const FObjectInitializer& ObjectInitializer)
{
	
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

