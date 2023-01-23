// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuBase.h"
#include "WB_Escape.generated.h"

class UEditableTextBox;
/**
 * 
 */
UCLASS()
class RPG_API UWB_Escape : public UMenuBase
{
	GENERATED_BODY()

public:

	void Setup(IMenuInterface* menuInterface, ISaveInterface* saveInterface) override;
	
	UFUNCTION()
	void SetAvaibleAllSlots(const FText& Text);

protected:
	
	UPROPERTY(meta=(BindWidget))
	UButton* BackButton;
	
	UPROPERTY(meta=(BindWidget))
	UButton* MainMenuButton;

	UPROPERTY(meta=(BindWidget))
	UEditableTextBox* SaveNameTextBox;

};
