// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterHUD.h"
#include "WB_Character.h"

ACharacterHUD::ACharacterHUD()
{
	static ConstructorHelpers::FClassFinder<UWB_Character> CharacterWidget_BP(TEXT("/Game/UI/WB_Character"));
	if (!ensure(CharacterWidget_BP.Class != nullptr)) return;

	CharacterWidget = CreateWidget<UWB_Character>(GetWorld(),CharacterWidget_BP.Class);

	if(CharacterWidget)
		CharacterWidget->AddToViewport(0);
}
