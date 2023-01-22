// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interfaces/MenuInterface.h"
#include "RPGPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class RPG_API ARPGPlayerController : public APlayerController, public IMenuInterface
{
	GENERATED_BODY()

public:
	
	ARPGPlayerController();

	void CreateMainMenu();

	virtual void BeginPlay() override;

	virtual void NewGame() override;

	virtual void ToMainMenu() override;

	virtual void EscapeMenuAction() override;

	virtual void Quit() override;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* MappingContext;

	/** Escape Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* EscapeAction;
	
private:
	
	virtual void SetupInputComponent() override;

	// To define Main Menu subclass
	TSubclassOf<class UUserWidget> MainMenuClass;

	// To define Escape Menu subclass
	TSubclassOf<class UUserWidget> EscapeMenuClass;

	// To define Main Menu class
	UPROPERTY()
	class UWB_MainMenu* MainMenu;
	// To define Escape Menu class
	UPROPERTY()
	class UWB_Escape* EscapeMenu;

	void SetupInputMode(bool bIsUI);
};
