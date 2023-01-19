// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RPG/Interfaces/MenuInterface.h"
#include "WB_MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API UWB_MainMenu : public UUserWidget
{
	GENERATED_BODY()

public:

	void Setup();

	void SetMenuInterface(IMenuInterface* Interface);

protected:

	// Define Interface
	IMenuInterface* MenuInterface;
	
};
