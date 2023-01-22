// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuBase.h"
#include "WB_MainMenu.generated.h"

class UWidgetSwitcher;
class UButton;
class IMenuInterface;
//class IMenuInterface;
/**
 * 
 */
UCLASS()
class RPG_API UWB_MainMenu : public UMenuBase
{
	GENERATED_BODY()

public:

	virtual void Setup(IMenuInterface* Interface) override;

protected:
	
	UFUNCTION()
	void LoadGamePanel();
	
	UFUNCTION()
	void MainPanel();

	UPROPERTY(meta=(BindWidget))
	UButton* LoadGameButton;
	UPROPERTY(meta=(BindWidget))
	UButton* LoadGameBackButton;
	UPROPERTY(meta=(BindWidget))
	UButton* NewGameButton;
	
	UPROPERTY(meta=(BindWidget))
	UWidgetSwitcher* MenuSwitcher;
};
