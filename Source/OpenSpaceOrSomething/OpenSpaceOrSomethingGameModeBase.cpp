// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenSpaceOrSomethingGameModeBase.h"

class SPlanetNumWidget;
class SMainWidget;
class ASpacePlayerController;

//is called when the game starts
void AOpenSpaceOrSomethingGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	planets_num = -1;
	message = TEXT("HELLO");


	//set the ASpaceController class as a default player controller class for this gamemode
	PlayerControllerClass = ASpacePlayerController::StaticClass();
	
	displayStartMenu();
	

	
	
}

void AOpenSpaceOrSomethingGameModeBase::displayStartMenu()
{
	StartWidget = SNew(SPlanetNumWidget).messageArg(message).ownerArg(this);
	if (GEngine)
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(StartWidget.ToSharedRef()));
	}

	StartWidget->SetVisibility(EVisibility::Visible);

}


void AOpenSpaceOrSomethingGameModeBase::redisplayMenu(FString prompt, int which)
{
	if(which == 0)
	{ 
		setMessage(prompt, -1);
		displayStartMenu();
	}
	
}

//MUST ADD ASSERTIONS ,CHECK FOR THE NULL PTRs
void AOpenSpaceOrSomethingGameModeBase::displayMainMenu(int32 index, SPlanetNumWidget* prevMenu, FString startMes)
{

	//widget is not visible and does not take space
	prevMenu->SetVisibility(EVisibility::Collapsed);
	
	setPlanetNum(index);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("will be moving to the main"));
	}

	//build the mainmenu widget and display it
	setMessage(startMes, index);
	CurrentWidget = SNew(SMainWidget).messageArg(message).ownerArg(this);

	if (GEngine)
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(CurrentWidget.ToSharedRef()));
	}

	CurrentWidget->SetVisibility(EVisibility::Visible);

}

void AOpenSpaceOrSomethingGameModeBase::setPlanetNum(int32 count)
{
	planets_num = count;
}

void AOpenSpaceOrSomethingGameModeBase::setMessage(FString mes, int32 val)
{
	FString add = FString(TEXT(" "));

	if (val != -1)
	{
		add = FString::FromInt(val);
	}
	message = mes + add;
}

