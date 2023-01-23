// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuBase.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/WidgetSwitcher.h"
#include "RPG/Interfaces/MenuInterface.h"
#include "RPG/Interfaces/SaveInterface.h"

void UMenuBase::Setup(IMenuInterface* menuInterface, ISaveInterface* saveInterface)
{
	MenuInterface = menuInterface;
	SaveInterface = saveInterface;
	QuitButton->OnClicked.AddDynamic(MenuInterface, &IMenuInterface::Quit);
	BackToMenuButton->OnClicked.AddDynamic(this, &UMenuBase::MainPanel);
	SavePanelButton->OnClicked.AddDynamic(this, &UMenuBase::SavePanel);
}

void UMenuBase::SetSlotName(uint8 SlotIndex, FString SlotName)
{
	switch (SlotIndex)
	{
	case 1:
		{
			Slot1Text->SetText(FText::FromString(SlotName));
			break;
		}
	case 2:
		{
			Slot2Text->SetText(FText::FromString(SlotName));
			break;
		}
	case 3:
		{
			Slot3Text->SetText(FText::FromString(SlotName));
			break;
		}
	case 4:
		{
			Slot4Text->SetText(FText::FromString(SlotName));
			break;
		}
	default: break;
	}
}

void UMenuBase::SavePanel()
{
	MenuSwitcher->SetActiveWidgetIndex(1);
	SaveInterface->CheckSaveGames(this);
}

void UMenuBase::MainPanel()
{
	MenuSwitcher->SetActiveWidgetIndex(0);
}
