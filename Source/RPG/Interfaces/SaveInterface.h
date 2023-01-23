// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SaveInterface.generated.h"

class UMenuBase;
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USaveInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class RPG_API ISaveInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void CheckSaveGames(UMenuBase* Menu) = 0;

	virtual void SaveGame(FString SaveName, FString SlotName) = 0;
};
