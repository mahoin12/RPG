// Fill out your copyright notice in the Description page of Project Settings.


#include "WB_Escape.h"
#include "Components/Button.h"
#include "Types/SlateEnums.h"
#include "Components/EditableTextBox.h"
#include "RPG/Interfaces/MenuInterface.h"
#include "RPG/Interfaces/SaveInterface.h"


void UWB_Escape::Setup(IMenuInterface* Interface, ISaveInterface* saveInterface)
{
	Super::Setup(Interface, saveInterface);
	BackButton->OnClicked.AddDynamic(MenuInterface, &IMenuInterface::EscapeMenuAction);
	MainMenuButton->OnClicked.AddDynamic(MenuInterface, &IMenuInterface::ToMainMenu);
	SaveNameTextBox->OnTextChanged.AddDynamic(this, &UWB_Escape::SetAvaibleAllSlots);
}

void UWB_Escape::SetAvaibleAllSlots(const FText& Text)
{
	if(Text.IsEmpty())
	{
		Slot1->SetIsEnabled(false);
		Slot2->SetIsEnabled(false);
		Slot3->SetIsEnabled(false);
		Slot4->SetIsEnabled(false);
	}
	else
	{
		Slot1->SetIsEnabled(true);
		Slot2->SetIsEnabled(true);
		Slot3->SetIsEnabled(true);
		Slot4->SetIsEnabled(true);
	}
}
