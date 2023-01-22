// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuBase.h"
#include "Components/Button.h"

void UMenuBase::Setup(IMenuInterface* Interface)
{
	MenuInterface = Interface;
	QuitButton->OnClicked.AddDynamic(MenuInterface, &IMenuInterface::Quit);
}
