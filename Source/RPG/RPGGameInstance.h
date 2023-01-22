// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/SaveInterface.h"
#include "Interfaces/StatsInterface.h"
#include "RPGGameInstance.generated.h"

enum class CharacterStats : uint8;
/**
 * 
 */
UCLASS()
class RPG_API URPGGameInstance : public UGameInstance, public IStatsInterface, public ISaveInterface
{
	GENERATED_BODY()

public:

	URPGGameInstance(const FObjectInitializer& ObjectInitializer);

	virtual void CheckSaveGames() override;

	virtual void SaveGame(FString SaveName) override;

private:

	CharacterStats CharacterStats;
};
