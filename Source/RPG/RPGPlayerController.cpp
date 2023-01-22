// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Kismet/GameplayStatics.h"
#include "UI/Menu/WB_Escape.h"
#include "UI/Menu/WB_MainMenu.h"

ARPGPlayerController::ARPGPlayerController()
{
	DefaultMouseCursor = EMouseCursor::Default;
	SetShowMouseCursor(false);

	ConstructorHelpers::FClassFinder<UWB_MainMenu> WB_MainMenu(TEXT("/Game/UI/WB_MainMenu"));
	if (!ensure(WB_MainMenu.Class != nullptr)) return;
	MainMenuClass =WB_MainMenu.Class;
	
	ConstructorHelpers::FClassFinder<UWB_Escape> WB_Escape(TEXT("/Game/UI/WB_Escape"));
	if (!ensure(WB_Escape.Class != nullptr)) return;
	EscapeMenuClass =WB_Escape.Class;
}

void ARPGPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	//Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(MappingContext, 0);
	}
	if(UGameplayStatics::GetCurrentLevelName(GetWorld(),true)=="MainMenu")
	{
		CreateMainMenu();
		SetupInputMode(true);
	}
	else
	{
		SetupInputMode(false);
	}
}

void ARPGPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		EnhancedInputComponent->BindAction(EscapeAction,ETriggerEvent::Started,this,&ARPGPlayerController::EscapeMenuAction);
	}
}

void ARPGPlayerController::EscapeMenuAction()
{
	if(!EscapeMenu)
	{
		EscapeMenu = CreateWidget<UWB_Escape>(GetWorld(),EscapeMenuClass);
		EscapeMenu->Setup(this);
	}
	if(EscapeMenu->IsInViewport())
	{
		EscapeMenu->RemoveFromParent();
		SetupInputMode(false);
	}
	else
	{
		EscapeMenu->AddToViewport(0);
		SetupInputMode(true);
	}
}

void ARPGPlayerController::CreateMainMenu()
{
	if(!MainMenu)
	{
		MainMenu = CreateWidget<UWB_MainMenu>(GetWorld(),MainMenuClass);
		if (!ensure(MainMenu != nullptr)) return;
		MainMenu->Setup(this);
	}
	MainMenu->AddToViewport(0);
	SetupInputMode(true);
}

void ARPGPlayerController::Quit()
{
	UKismetSystemLibrary::QuitGame(GetWorld(),0,EQuitPreference::Quit,false);
}

void ARPGPlayerController::NewGame()
{
	// Check for avaible MainMenu class if true then close MainMenu widget
	if (MainMenu != nullptr) MainMenu->RemoveFromParent();
	
	UGameplayStatics::OpenLevel(GetWorld(),"StartLevel",true);
	SetupInputMode(false);
}

void ARPGPlayerController::ToMainMenu()
{
	UGameplayStatics::OpenLevel(GetWorld(),"MainMenu",true);
}

void ARPGPlayerController::SetupInputMode(bool bIsUI)
{
	// Setting parameters
	if(bIsUI)
	{
		FInputModeUIOnly InputModeData;
		InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
		SetInputMode(InputModeData);
	}
	else
	{
		FInputModeGameOnly InputModeData;
		SetInputMode(InputModeData);
	}
	SetShowMouseCursor(bIsUI);
	SetPause(bIsUI);
}
