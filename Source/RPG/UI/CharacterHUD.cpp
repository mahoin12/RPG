// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterHUD.h"
#include "CharacterWidget.h"

ACharacterHUD::ACharacterHUD()
{
	static ConstructorHelpers::FClassFinder<UCharacterWidget> CharacterWidget_BP(TEXT("/Game/UI/CharacterWidget"));
	if (!ensure(CharacterWidget_BP.Class != nullptr)) return;

	CharacterWidget = CreateWidget<UCharacterWidget>(GetWorld(),CharacterWidget_BP.Class);

	if(CharacterWidget)
		CharacterWidget->AddToViewport(0);
}
