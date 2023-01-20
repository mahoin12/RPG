// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/MenuInterface.h"
#include "Interfaces/StatsInterface.h"
#include "RPGGameInstance.generated.h"

enum class CharacterStats : uint8;
/**
 * 
 */
UCLASS()
class RPG_API URPGGameInstance : public UGameInstance, public IMenuInterface, public IStatsInterface
{
	GENERATED_BODY()

public:

	URPGGameInstance(const FObjectInitializer& ObjectInitializer);

	void CreateEscapeMenu();

	void CreateMenu();
	
	void LoadMainMenu();

	virtual void Quit() override;

	virtual void CheckSaveGames() override;

	virtual void SaveGame(FString SaveName) override;

	virtual void NewGame() override;

	virtual void BackToGame() override;

	virtual void ToMainMenu() override;

private:

	// To define Main Menu subclass
	TSubclassOf<class UUserWidget> MainMenuClass;

	// To define Escape Menu subclass
	TSubclassOf<class UUserWidget> EscapeMenuClass;

	// To define Main Menu class
	UPROPERTY()
	class UWB_MainMenu* MainMenu;
	// To define Escape Menu class
	UPROPERTY()
	class UWB_Escape* EscapeMenu;

	CharacterStats CharacterStats;
};
