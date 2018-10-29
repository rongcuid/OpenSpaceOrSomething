// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenSpaceOrSomethingGameModeBase.h"


void AOpenSpaceOrSomethingGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	//ChangeWidget(MainWidget);
}

void AOpenSpaceOrSomethingGameModeBase::ChangeWidget(SMainWidget NewWidgetClass)
{
	//if current widget is not empty
	//remove it from the view port
	//if the new widget is not empty
	//add the widget to the viewport
}
