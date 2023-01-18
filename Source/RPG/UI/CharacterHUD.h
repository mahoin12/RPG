// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CharacterHUD.generated.h"

class UCharacterWidget;
/**
 * 
 */
UCLASS()
class RPG_API ACharacterHUD : public AHUD
{
	GENERATED_BODY()

	ACharacterHUD();

public:

	FORCEINLINE UCharacterWidget* GetCharacterWidget() const {return CharacterWidget;}

protected:

	UPROPERTY()
	UCharacterWidget* CharacterWidget;
	
	
};
