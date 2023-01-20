// Fill out your copyright notice in the Description page of Project Settings.


#include "WB_MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "RPG/Interfaces/MenuInterface.h"


void UWB_MainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	LoadGameButton->OnClicked.AddDynamic(this, &UWB_MainMenu::LoadGamePanel);
	LoadGameBackButton->OnClicked.AddDynamic(this, &UWB_MainMenu::MainPanel);
}

void UWB_MainMenu::Setup(IMenuInterface* Interface)
{
	MenuInterface=Interface;
	QuitButton->OnClicked.AddDynamic(MenuInterface, &IMenuInterface::Quit);
	NewGameButton->OnClicked.AddDynamic(MenuInterface, &IMenuInterface::NewGame);
}

void UWB_MainMenu::LoadGamePanel()
{
	MenuSwitcher->SetActiveWidgetIndex(1);
}

void UWB_MainMenu::MainPanel()
{
	MenuSwitcher->SetActiveWidgetIndex(0);
}

