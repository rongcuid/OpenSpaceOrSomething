// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SlateBasics.h"
#include "OpenSpaceOrSomethingGameModeBase.h"

class AOpenSpaceOrSomethingGameModeBase;
/**
 * the widget SPlanetNumWidget gets the numbe of widgets from the player
 */
class OPENSPACEORSOMETHING_API SPlanetNumWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SPlanetNumWidget){}

	//give the pointer to the prompt/error
	SLATE_ARGUMENT(FString, messageArg);

	//give the pointer to parent
	SLATE_ARGUMENT(AOpenSpaceOrSomethingGameModeBase*, ownerArg);


	SLATE_END_ARGS();

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	//event triggered by change in the text of the textbox
	//that will get the number of planets and assign to a variable
	//void OnAddTextChanged(const FText& InText);


	FReply OnStartClicked();


	TSharedPtr<SButton> NUMButton;
	TSharedPtr<SEditableTextBox> NumberInPut;
	FString prompt;
	AOpenSpaceOrSomethingGameModeBase* parent;
	
};
