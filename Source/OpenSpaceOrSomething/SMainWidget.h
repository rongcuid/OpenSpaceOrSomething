// Fill out your copyright notice in the Description page of Project Settings.

/*the class MainWidget will impement the main menu; inherits from a Compond Slata Widget*/
#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "SlateBasics.h"
#include "OpenSpaceOrSomethingGameModeBase.h"

class AOpenSpaceOrSomethingGameModeBase;
/**
 * main menu widget 
 */
class OPENSPACEORSOMETHING_API SMainWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainWidget){}

	//give the pointer to the prompt/error/number of planets tracking
	SLATE_ARGUMENT(FString, messageArg);

	//give the pointer to parent
	SLATE_ARGUMENT(AOpenSpaceOrSomethingGameModeBase*, ownerArg);

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	void OnMassChanged(const FText& InText);
	void OnXChanged(const FText& InText);
	void OnYChanged(const FText& InText);
	void OnZChanged(const FText& InText);
	void OnVelocityXChanged(const FText& InText);
	void OnVelocityYChanged(const FText& InText);
	void OnVelocityZChanged(const FText& InText);

	FReply OnAddClicked();
	FReply OnPlayClicked();
	FReply OnMoreClicked();

	TSharedPtr<SButton> AddNextButton;
	TSharedPtr<SButton> PlayButton;
	TSharedPtr<SButton> MoreButton;

	TSharedPtr<SEditableTextBox> MassInPut;

	TSharedPtr<SEditableTextBox> XInPut;
	TSharedPtr<SEditableTextBox> YInPut;
	TSharedPtr<SEditableTextBox> ZInPut;

	TSharedPtr<SEditableTextBox> VxInPut;
	TSharedPtr<SEditableTextBox> VyInPut;
	TSharedPtr<SEditableTextBox> VzInPut;

	FString prompt;
	AOpenSpaceOrSomethingGameModeBase* parent;
};
