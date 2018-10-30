// Fill out your copyright notice in the Description page of Project Settings.

#include "SInGameWidget.h"
#include "SlateOptMacros.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SInGameWidget::Construct(const FArguments& InArgs)
{
	prompt = InArgs._messageArg;
	parent = InArgs._ownerArg;///gamemode pointer

	ChildSlot.VAlign(VAlign_Fill).HAlign(HAlign_Fill)
	[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()//errors and prompts box
			[
				SNew(STextBlock)//for the error message output
				.ShadowColorAndOpacity(FLinearColor::Black)
				.ColorAndOpacity(FLinearColor::Red)
				.ShadowOffset(FIntPoint(-1, 1))
				.Font(FSlateFontInfo("Verdana", 34))
				.Text(FText::FromString(prompt))//change to empty later to start with
			]
			+ SVerticalBox::Slot()//buttons block
			.Padding(FMargin(520.0f, 20.0f, 520.0f, 50.0f))
			[
					SNew(SBorder).Padding(FMargin(3))
					.BorderBackgroundColor(FLinearColor::Blue)
					[
						SNew(SHorizontalBox)//add more button
						+ SHorizontalBox::Slot()
						[
								SAssignNew(AddMoreButton, SButton)
								.ButtonStyle(FCoreStyle::Get(), "NoBorder")
								.HAlign(HAlign_Center).VAlign(VAlign_Center)
								.OnClicked(this, &SInGameWidget::OnAddClicked)
								[
										SNew(SBorder).Padding(FMargin(3))
										.BorderBackgroundColor(FLinearColor::Blue)
										[
											SNew(STextBlock)
											.ShadowColorAndOpacity(FLinearColor::Black)
											.ColorAndOpacity(FLinearColor::Red)
											.ShadowOffset(FIntPoint(-1, 1))
											.Font(FSlateFontInfo("Verdana", 34))
											.Text(FText::FromString("ADD MORE PLANET"))
										]
								]
						]
						+ SHorizontalBox::Slot()//save button
						[
								SAssignNew(PlayButton, SButton)
								.ButtonStyle(FCoreStyle::Get(), "NoBorder")
								.HAlign(HAlign_Center).VAlign(VAlign_Center)
								.OnClicked(this, &SInGameWidget::OnAddClicked)
								[
										SNew(SBorder).Padding(FMargin(3))
										.BorderBackgroundColor(FLinearColor::Blue)
										[
											SNew(STextBlock)
											.ShadowColorAndOpacity(FLinearColor::Black)
											.ColorAndOpacity(FLinearColor::Red)
											.ShadowOffset(FIntPoint(-1, 1))
											.Font(FSlateFontInfo("Verdana", 34))
											.Text(FText::FromString("RENDER PLANETS"))
										]
								]
						]
						+ SHorizontalBox::Slot()//exit button
						[
									SAssignNew(ExitButton, SButton)
									.ButtonStyle(FCoreStyle::Get(), "NoBorder")
									.HAlign(HAlign_Center).VAlign(VAlign_Center)
									.OnClicked(this, &SInGameWidget::OnAddClicked)
									[
										SNew(SBorder).Padding(FMargin(3))
										.BorderBackgroundColor(FLinearColor::Blue)
										[
											SNew(STextBlock)
											.ShadowColorAndOpacity(FLinearColor::Black)
											.ColorAndOpacity(FLinearColor::Red)
											.ShadowOffset(FIntPoint(-1, 1))
											.Font(FSlateFontInfo("Verdana", 34))
											.Text(FText::FromString("EXIT GAME"))
										]
									]
						]
							
		            ]//border buttons block
			     ]//vertical buttons
		
		];//child slot
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
