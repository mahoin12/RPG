// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuBase.h"
#include "WB_Escape.generated.h"

class UButton;
class IMenuInterface;
/**
 * 
 */
UCLASS()
class RPG_API UWB_Escape : public UMenuBase
{
	GENERATED_BODY()

public:

	virtual void Setup(IMenuInterface* Interface) override;

protected:

	UPROPERTY(meta=(BindWidget))
	UButton* BackButton;
	UPROPERTY(meta=(BindWidget))
	UButton* MainMenuButton;
	
};
