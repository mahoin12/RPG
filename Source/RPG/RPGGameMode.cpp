// Copyright Epic Games, Inc. All Rights Reserved.

#include "RPGGameMode.h"
#include "RPGGameInstance.h"
#include "RPGPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "UI/CharacterHUD.h"
#include "UObject/ConstructorHelpers.h"

ARPGGameMode::ARPGGameMode()
{

	// use our custom PlayerController class
	PlayerControllerClass = ARPGPlayerController::StaticClass();

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_RPGPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
	
	if(UGameplayStatics::GetCurrentLevelName(GetWorld(),true)=="MainMenu")
	{
		Cast<URPGGameInstance>(GetGameInstance())->CreateMenu();
	}
	else
	{
		// set default pawn class to our Blueprinted character
		static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
		if (PlayerPawnBPClass.Class != NULL)
		{
			DefaultPawnClass = PlayerPawnBPClass.Class;
		}
		HUDClass = ACharacterHUD::StaticClass();
	}
}
