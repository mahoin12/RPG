// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/MenuInterface.h"
#include "RPGGameInstance.generated.h"

enum class CharacterStats : uint8;
/**
 * 
 */
UCLASS()
class RPG_API URPGGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()

public:

	URPGGameInstance(const FObjectInitializer& ObjectInitializer);

	void CreateMenu();
	
	void LoadMainMenu();

	virtual void Quit();

	virtual void CheckSaveGames();

	virtual void SaveGame(FString SaveName);

private:

	// To define Main Menu class
	UPROPERTY()
	class UWB_MainMenu* MainMenu;

	CharacterStats CharacterStats;
};
