// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SlateBasics.h"
#include "OpenSpaceOrSomethingGameModeBase.h"

class AOpenSpaceOrSomethingGameModeBase;
/**
 * SInGameWidget class is meant for the menu that allows to add more
 planets, save the data and exit the game
 */
class OPENSPACEORSOMETHING_API SInGameWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SInGameWidget){}

	//give the pointer to the prompt/error/number of planets tracking
	SLATE_ARGUMENT(FString, messageArg);

	//give the pointer to parent
	SLATE_ARGUMENT(AOpenSpaceOrSomethingGameModeBase*, ownerArg);

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	void OnAddMoreChanged(const FText& InText);
	void OnSaveChanged(const FText& InText);
	void OnExitChanged(const FText& InText);

	FReply OnAddClicked();
	FReply OnPlayClicked();
	FReply OnExitClicked();

	TSharedPtr<SButton> AddNextButton;
	TSharedPtr<SButton> PlayButton;
	TSharedPtr<SButton> ExitButton;

	FString prompt;
	AOpenSpaceOrSomethingGameModeBase* parent;
};
