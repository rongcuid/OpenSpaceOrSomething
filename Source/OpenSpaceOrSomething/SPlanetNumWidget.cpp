// Fill out your copyright notice in the Description page of Project Settings.

#include "SPlanetNumWidget.h"
#include "SlateOptMacros.h"
//for onscreen printing, delete later
#include "Runtime/Engine/Classes/Engine/Engine.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SPlanetNumWidget::Construct(const FArguments& InArgs)
{
	prompt = InArgs._messageArg;
	parent = InArgs._ownerArg;///gamemode pointer

	//widget_temp = TEXT("");

	ChildSlot.VAlign(VAlign_Fill).HAlign(HAlign_Fill)
	[
		SNew(SVerticalBox)
		+ SVerticalBox::Slot()
		.Padding(FMargin(520.0f, 20.0f, 520.0f, 50.0f))
		[
			SNew(SBorder).Padding(FMargin(3))
			.BorderBackgroundColor(FLinearColor::Blue)
			[

				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
		       .Padding(FMargin(520.0f, 20.0f, 520.0f, 50.0f))
		        [

						SNew(STextBlock)//for the error message output
						.ShadowColorAndOpacity(FLinearColor::Black)
						.ColorAndOpacity(FLinearColor::Red)
						.ShadowOffset(FIntPoint(-1, 1))
						.Font(FSlateFontInfo("Verdana", 34))
						.Text(FText::FromString(prompt))//change to empty later to start with
				]
				+ SVerticalBox::Slot()
				[
					SNew(SHorizontalBox)
					+ SHorizontalBox::Slot()//edible textbox and add button 
					[
						SAssignNew(NumberInPut, SEditableTextBox)
						.Text(FText::FromString(""))
						.Font(FSlateFontInfo("Verdana", 34))
						.HintText(FText::FromString("Enter Number of Planets Here: whole numbers"))
						.OnTextChanged(this, &SPlanetNumWidget::OnAddTextChanged)
					]
					+ SHorizontalBox::Slot()
					[
						SAssignNew(NUMButton, SButton)
						.ButtonStyle(FCoreStyle::Get(), "NoBorder")
						.HAlign(HAlign_Center).VAlign(VAlign_Center)
						.OnClicked(this, &SPlanetNumWidget::OnStartClicked)
						[
							SNew(SBorder).Padding(FMargin(3))
							.BorderBackgroundColor(FLinearColor::Blue)
							[
								SNew(STextBlock)
								.ShadowColorAndOpacity(FLinearColor::Black)
								.ColorAndOpacity(FLinearColor::Red)
								.ShadowOffset(FIntPoint(-1, 1))
								.Font(FSlateFontInfo("Verdana", 34))
								.Text(FText::FromString(" START "))
							]
						]
					]
				]//vertical box end
		
			]//border end
		]//vertical box end
		
	];//childslot end
}

void SPlanetNumWidget::OnAddTextChanged(const FText & InText)
{
}

FReply SPlanetNumWidget::OnStartClicked()
{
	parent->displayMainMenu(5, this);
	return FReply::Handled();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
