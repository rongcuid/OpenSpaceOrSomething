// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SMainWidget.h"
#include "SPlanetNumWidget.h"
#include "DataStruct.h"
#include "SlateBasics.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Widgets/SWeakWidget.h"
#include "SpacePlayerController.h"
#include "OpenSpaceOrSomethingGameModeBase.generated.h"

class SPlanetNumWidget;

/**
 * AOpenSpaceOrSomethingGameModeBase class for the main game mode
	indexed the widgets for now:
	0: gets the number of planets
	1: main menu
	2: ingame menu
 */
UCLASS()
class OPENSPACEORSOMETHING_API AOpenSpaceOrSomethingGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
		
public:
	/** Remove the current start widget and add dmain info menu another */
	void displayMainMenu(int32 count, SPlanetNumWidget* prevWidget, FString outMessage);
	void setPlanetNum(int32 count);
	void setMessage(FString mes,int32 value);




	//redisplay the menu if there were a validation error 
	void redisplayMenu(FString prompt, int index);

	//start widget is the SPlanetNumWidget to get the number of planets
	TSharedPtr<SWidget> StartWidget;

	/** The widget instance that will behave as temp variable */
	TSharedPtr<SWidget> CurrentWidget;

	int32 planets_num;

	FString message;

protected:
	/** Called when the game starts. */
	virtual void BeginPlay() override;
	void displayStartMenu();

	
};
