// Fill out your copyright notice in the Description page of Project Settings.


#include "WB_MainMenu.h"
#include "Kismet/GameplayStatics.h"
#include "RPG/RPGPlayerController.h"
#include "RPG/Interfaces/MenuInterface.h"

void UWB_MainMenu::Setup()
{
	this->AddToViewport();

	UWorld* World = GetWorld();
	// Check for a valid World
	if (!ensure(World != nullptr)) return;
	// Getting player controller
	ARPGPlayerController* PlayerController = Cast<ARPGPlayerController>(UGameplayStatics::GetPlayerController(World,0));
	// Check for player controller
	if (!ensure(PlayerController != nullptr)) return;
	// Setting parameters
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}

void UWB_MainMenu::SetMenuInterface(IMenuInterface* Interface)
{
	MenuInterface=Interface;
}
