// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CharacterHUD.generated.h"

class UWB_Character;
/**
 * 
 */
UCLASS()
class RPG_API ACharacterHUD : public AHUD
{
	GENERATED_BODY()

	ACharacterHUD();

public:

	FORCEINLINE UWB_Character* GetCharacterWidget() const {return CharacterWidget;}

protected:

	UPROPERTY()
	UWB_Character* CharacterWidget;
	
	
};
