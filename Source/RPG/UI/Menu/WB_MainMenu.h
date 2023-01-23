// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuBase.h"
#include "WB_MainMenu.generated.h"

//class IMenuInterface;
/**
 * 
 */
UCLASS()
class RPG_API UWB_MainMenu : public UMenuBase
{
	GENERATED_BODY()

public:

	void Setup(IMenuInterface* IntemenuInterfacerface, ISaveInterface* saveInterface) override;

protected:
	
	UPROPERTY(meta=(BindWidget))
	UButton* NewGameButton;
};
