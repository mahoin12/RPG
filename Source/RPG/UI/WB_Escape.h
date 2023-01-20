// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WB_Escape.generated.h"

class UButton;
class IMenuInterface;
/**
 * 
 */
UCLASS()
class RPG_API UWB_Escape : public UUserWidget
{
	GENERATED_BODY()

public:

	void Setup(IMenuInterface* Interface);

protected:

	// Define Interface
	IMenuInterface* MenuInterface;

	UPROPERTY(meta=(BindWidget))
	UButton* QuitButton;

	UPROPERTY(meta=(BindWidget))
	UButton* BackButton;

	UPROPERTY(meta=(BindWidget))
	UButton* MainMenuButton;
};
