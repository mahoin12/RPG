// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RPG/Interfaces/MenuInterface.h"
#include "WB_MainMenu.generated.h"

class UWidgetSwitcher;
class UButton;
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

	void SetSlotActive(uint8 SlotIndex);
	

protected:
	
	UFUNCTION()
	void LoadGamePanel();
	UFUNCTION()
	void MainPanel();
	UFUNCTION()
	void Quit();

	
	virtual void NativeConstruct() override;

	// Define Interface
	IMenuInterface* MenuInterface;

	UPROPERTY(meta=(BindWidget))
	UButton* LoadGameButton;
	UPROPERTY(meta=(BindWidget))
	UButton* LoadGameBackButton;
	UPROPERTY(meta=(BindWidget))
	UButton* QuitButton;
	UPROPERTY(meta=(BindWidget))
	UButton* Slot1;
	UPROPERTY(meta=(BindWidget))
	UButton* Slot2;
	UPROPERTY(meta=(BindWidget))
	UButton* Slot3;
	UPROPERTY(meta=(BindWidget))
	UButton* Slot4;
	
	UPROPERTY(meta=(BindWidget))
	UWidgetSwitcher* MenuSwitcher;
};
