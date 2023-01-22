// Fill out your copyright notice in the Description page of Project Settings.


#include "WB_Escape.h"

#include "Components/Button.h"
#include "RPG/Interfaces/MenuInterface.h"


void UWB_Escape::Setup(IMenuInterface* Interface)
{
	MenuInterface = Interface;
	QuitButton->OnClicked.AddDynamic(MenuInterface, &IMenuInterface::Quit);
	BackButton->OnClicked.AddDynamic(MenuInterface, &IMenuInterface::EscapeMenuAction);
	MainMenuButton->OnClicked.AddDynamic(MenuInterface, &IMenuInterface::ToMainMenu);
}
