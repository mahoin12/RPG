// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuBase.generated.h"

class ISaveInterface;
class IMenuInterface;
class UWidgetSwitcher;
class UButton;
class UTextBlock;
/**
 * 
 */
UCLASS()
class RPG_API UMenuBase : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void Setup(IMenuInterface* menuInterface, ISaveInterface* saveInterface);

	void SetSlotName(uint8 SlotIndex, FString SlotName);

protected:

	// Define Interfaces
	IMenuInterface* MenuInterface;
	ISaveInterface* SaveInterface;

	UFUNCTION()
	void SavePanel();
	
	UFUNCTION()
	void MainPanel();

	UPROPERTY(meta=(BindWidget))
	UButton* SavePanelButton;

	UPROPERTY(meta=(BindWidget))
	UButton* BackToMenuButton;

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
	UTextBlock* Slot1Text;
	UPROPERTY(meta=(BindWidget))
	UTextBlock* Slot2Text;
	UPROPERTY(meta=(BindWidget))
	UTextBlock* Slot3Text;
	UPROPERTY(meta=(BindWidget))
	UTextBlock* Slot4Text;

	UPROPERTY(meta=(BindWidget))
	UWidgetSwitcher* MenuSwitcher;
};
