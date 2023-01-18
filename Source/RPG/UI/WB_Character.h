// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WB_Character.generated.h"

class UProgressBar;
/**
 * 
 */
UCLASS()
class RPG_API UWB_Character : public UUserWidget
{
	GENERATED_BODY()

public:

protected:

	UPROPERTY(meta=(BindWidget))
	UProgressBar* PB_Health;
	UPROPERTY(meta=(BindWidget))
	UProgressBar* PB_Mana;
	UPROPERTY(meta=(BindWidget))
	UProgressBar* PB_Stamina;

private:
	
};
