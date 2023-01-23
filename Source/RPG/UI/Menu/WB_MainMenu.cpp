// Fill out your copyright notice in the Description page of Project Settings.


#include "WB_MainMenu.h"
#include "Components/Button.h"
#include "RPG/Interfaces/MenuInterface.h"


void UWB_MainMenu::Setup(IMenuInterface* Interface, ISaveInterface* saveInterface)
{
	Super::Setup(Interface, saveInterface);
	NewGameButton->OnClicked.AddDynamic(MenuInterface, &IMenuInterface::NewGame);
}


