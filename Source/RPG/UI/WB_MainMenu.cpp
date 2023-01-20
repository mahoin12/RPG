// Fill out your copyright notice in the Description page of Project Settings.


#include "WB_MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Kismet/GameplayStatics.h"
#include "RPG/RPGPlayerController.h"
#include "RPG/Interfaces/MenuInterface.h"


void UWB_MainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	LoadGameButton->OnClicked.AddDynamic(this, &UWB_MainMenu::LoadGamePanel);
	LoadGameBackButton->OnClicked.AddDynamic(this, &UWB_MainMenu::MainPanel);
	QuitButton->OnClicked.AddDynamic(this, &UWB_MainMenu::Quit);
}

void UWB_MainMenu::Setup()
{
	this->AddToViewport();

	UWorld* World = GetWorld();
	// Check for a valid World
	if (!ensure(World != nullptr)) return;
	// Getting player controller
	ARPGPlayerController* PlayerController = Cast<ARPGPlayerController>(UGameplayStatics::GetPlayerController(World,0));
	// Check for player controller
	if (PlayerController)
	{
		// Setting parameters
		FInputModeUIOnly InputModeData;
		InputModeData.SetWidgetToFocus(this->TakeWidget());
		InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		PlayerController->SetInputMode(InputModeData);
		PlayerController->SetShowMouseCursor(true);
	}
}

void UWB_MainMenu::SetMenuInterface(IMenuInterface* Interface)
{
	MenuInterface=Interface;
}

void UWB_MainMenu::LoadGamePanel()
{
	MenuSwitcher->SetActiveWidgetIndex(1);
}

void UWB_MainMenu::MainPanel()
{
	MenuSwitcher->SetActiveWidgetIndex(0);
}

void UWB_MainMenu::Quit()
{
	MenuInterface->Quit();
}


