// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RPG/Interfaces/MenuInterface.h"
#include "MenuBase.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class RPG_API UMenuBase : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void Setup(IMenuInterface* Interface);

protected:

	// Define Interface
	IMenuInterface* MenuInterface;

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
};
