// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "RPGSaveGame.generated.h"

enum class CharacterStats : uint8;
/**
 * 
 */
UCLASS()
class RPG_API URPGSaveGame : public USaveGame
{
	GENERATED_BODY()

	FORCEINLINE CharacterStats GetCharacterStats() const { return CharacterStats; }
	FORCEINLINE void SetCharacterStats(const CharacterStats Stats) { CharacterStats = Stats; }
	
private:

	UPROPERTY()
	CharacterStats CharacterStats;
};
