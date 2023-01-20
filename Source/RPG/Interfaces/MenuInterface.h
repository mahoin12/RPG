// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MenuInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UMenuInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_API IMenuInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION()
	virtual void Quit() = 0;
	
	virtual void CheckSaveGames() = 0;

	virtual void SaveGame(FString SaveName) = 0;

	UFUNCTION()
	virtual void NewGame() = 0;

	UFUNCTION()
	virtual void BackToGame() = 0;

	UFUNCTION()
	virtual void ToMainMenu() = 0;
};
