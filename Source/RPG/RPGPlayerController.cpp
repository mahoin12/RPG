// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "RPGGameInstance.h"

ARPGPlayerController::ARPGPlayerController()
{
	DefaultMouseCursor = EMouseCursor::Default;
}

void ARPGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MappingContext, 0);
	}
}

void ARPGPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(EscapeAction,ETriggerEvent::Started,Cast<URPGGameInstance>(GetGameInstance()),&URPGGameInstance::CreateEscapeMenu);
	}
}
