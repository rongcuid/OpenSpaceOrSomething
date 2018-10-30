// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SMainWidget.h"
#include "OpenSpaceOrSomethingGameModeBase.generated.h"


/**
 * AOpenSpaceOrSomethingGameModeBase class for the main game mode
 */
UCLASS()
class OPENSPACEORSOMETHING_API AOpenSpaceOrSomethingGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	/** Remove the current menu widget and add another */
	void ChangeWidget(SMainWidget NewWidgetClass);

protected:
	/** Called when the game starts. */
	virtual void BeginPlay() override;

	/** The widget class we will use as our menu when the game starts. */
	SMainWidget MainWidget;

	/** The widget instance that will behave as temp variable */
	SMainWidget* CurrentWidget;
	TArray<FText> data;
	
	
	
	
};
