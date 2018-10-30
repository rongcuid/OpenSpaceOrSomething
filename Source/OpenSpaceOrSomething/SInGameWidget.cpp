// Fill out your copyright notice in the Description page of Project Settings.

#include "SInGameWidget.h"
#include "SlateOptMacros.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInGameWidget::Construct(const FArguments& InArgs)
{
	/*
	ChildSlot
	[
		// Populate the widget
	];
	*/
}
void SInGameWidget::OnAddMoreChanged(const FText & InText)
{
}
void SInGameWidget::OnSaveChanged(const FText & InText)
{
}
void SInGameWidget::OnExitChanged(const FText & InText)
{
}
FReply SInGameWidget::OnAddClicked()
{
	return FReply::Handled();
}
FReply SInGameWidget::OnPlayClicked()
{
	return FReply::Handled();
}
FReply SInGameWidget::OnExitClicked()
{
	return FReply::Handled();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
