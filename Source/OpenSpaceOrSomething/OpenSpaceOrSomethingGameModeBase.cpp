// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenSpaceOrSomethingGameModeBase.h"

class SPlanetNumWidget;

void AOpenSpaceOrSomethingGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	planets_num = -1;
	message = TEXT("HELLO");

	StartWidget = SNew(SPlanetNumWidget).messageArg(message).ownerArg(this);

	if (GEngine)
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(StartWidget.ToSharedRef()));
	}

	StartWidget->SetVisibility(EVisibility::Visible);

	
	
}

void AOpenSpaceOrSomethingGameModeBase::displayMainMenu(int32 index, SPlanetNumWidget* prevMenu)
{

	//widget is not visible and does not take space
	prevMenu->SetVisibility(EVisibility::Collapsed);
	
	

	setPlanetNum(index);

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("will be moving to the main"));
	}
}

void AOpenSpaceOrSomethingGameModeBase::setPlanetNum(int32 count)
{
	planets_num = count;
}

