// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterStats.h"
#include "GameFramework/SaveGame.h"
#include "RPGSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API URPGSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	
	FORCEINLINE CharacterStats GetCharacterStats() const { return RPGCharacterStats; }
	FORCEINLINE void SetCharacterStats(const CharacterStats Stats) { RPGCharacterStats = Stats; }
	FORCEINLINE FString GetSaveGameName() const { return SaveGameName; }
	FORCEINLINE void SetSaveGameName(const FString Val) { SaveGameName = Val; }
	
private:
	
	CharacterStats RPGCharacterStats;

	FString SaveGameName;
};
