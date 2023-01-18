// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterWidget.generated.h"

class UProgressBar;
/**
 * 
 */
UCLASS()
class RPG_API UCharacterWidget : public UUserWidget
{
	GENERATED_BODY()

public:

protected:

	UPROPERTY(meta=(BindWidget))
	UProgressBar* HealthPB;
	UPROPERTY(meta=(BindWidget))
	UProgressBar* ManaPB;
	UPROPERTY(meta=(BindWidget))
	UProgressBar* StaminaPB;

private:
	
};
