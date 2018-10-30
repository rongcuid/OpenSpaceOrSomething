// Fill out your copyright notice in the Description page of Project Settings.

/*the menu for the main data collection for a planet*/

#include "SMainWidget.h"
#include "SlateOptMacros.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainWidget::Construct(const FArguments& InArgs)
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
			+ SVerticalBox::Slot()//mass
			.Padding(FMargin(520.0f, 20.0f, 520.0f, 50.0f))
			[
					SNew(SBorder).Padding(FMargin(3))
					.BorderBackgroundColor(FLinearColor::Blue)
					[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							[
								SNew(STextBlock)
								.ShadowColorAndOpacity(FLinearColor::Black)
								.ColorAndOpacity(FLinearColor::Red)
								.ShadowOffset(FIntPoint(-1, 1))
								.Font(FSlateFontInfo("Verdana", 34))
								.Text(FText::FromString(" ENTER MASS "))
							]
							+ SHorizontalBox::Slot()
							[
								SAssignNew(MassInPut, SEditableTextBox)
								.Text(FText::FromString(""))
								.Font(FSlateFontInfo("Verdana", 34))
								.HintText(FText::FromString("Enter Mass Value Here"))
								.OnTextChanged(this, &SMainWidget::OnMassChanged)
							]
		            ]//border mass
			]//vertical 2
			+ SVerticalBox::Slot()//x 
			[
					SNew(SBorder).Padding(FMargin(3))
					.BorderBackgroundColor(FLinearColor::Blue)
					[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							[
									SNew(STextBlock)
									.ShadowColorAndOpacity(FLinearColor::Black)
									.ColorAndOpacity(FLinearColor::Red)
									.ShadowOffset(FIntPoint(-1, 1))
									.Font(FSlateFontInfo("Verdana", 34))
									.Text(FText::FromString(" ENTER coordinate X "))
							]
						+ SHorizontalBox::Slot()
							[
								SAssignNew(XInPut, SEditableTextBox)
								.Text(FText::FromString(""))
								.Font(FSlateFontInfo("Verdana", 34))
								.HintText(FText::FromString("Enter coordinate X Here"))
								.OnTextChanged(this, &SMainWidget::OnXChanged)
							]
					]//borderx
			]

			+ SVerticalBox::Slot()//y
			[
					SNew(SBorder).Padding(FMargin(3))
					.BorderBackgroundColor(FLinearColor::Blue)
					[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							[
								SNew(STextBlock)
								.ShadowColorAndOpacity(FLinearColor::Black)
								.ColorAndOpacity(FLinearColor::Red)
								.ShadowOffset(FIntPoint(-1, 1))
								.Font(FSlateFontInfo("Verdana", 34))
								.Text(FText::FromString(" ENTER coordinate Y "))
							]
						+ SHorizontalBox::Slot()
							[
								SAssignNew(YInPut, SEditableTextBox)
								.Text(FText::FromString(""))
								.Font(FSlateFontInfo("Verdana", 34))
								.HintText(FText::FromString("Enter coordinate Y Here"))
								.OnTextChanged(this, &SMainWidget::OnYChanged)
							]
					]//bordery
			]
			+ SVerticalBox::Slot()//z
			[
					SNew(SBorder).Padding(FMargin(3))
					.BorderBackgroundColor(FLinearColor::Blue)
					[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							[
								SNew(STextBlock)
								.ShadowColorAndOpacity(FLinearColor::Black)
								.ColorAndOpacity(FLinearColor::Red)
								.ShadowOffset(FIntPoint(-1, 1))
								.Font(FSlateFontInfo("Verdana", 34))
								.Text(FText::FromString(" ENTER coordinate Z "))
							]
						+ SHorizontalBox::Slot()
							[
								SAssignNew(ZInPut, SEditableTextBox)
								.Text(FText::FromString(""))
								.Font(FSlateFontInfo("Verdana", 34))
								.HintText(FText::FromString("Enter Z coordinate Here"))
								.OnTextChanged(this, &SMainWidget::OnZChanged)
							]
					]//borderz
				]

			+ SVerticalBox::Slot()//Vx
				[
					SNew(SBorder).Padding(FMargin(3))
					.BorderBackgroundColor(FLinearColor::Blue)
					[
							SNew(SHorizontalBox)
							+ SHorizontalBox::Slot()
							[
									SNew(STextBlock)
									.ShadowColorAndOpacity(FLinearColor::Black)
									.ColorAndOpacity(FLinearColor::Red)
									.ShadowOffset(FIntPoint(-1, 1))
									.Font(FSlateFontInfo("Verdana", 34))
									.Text(FText::FromString(" ENTER Vx velocity "))
							]
						+ SHorizontalBox::Slot()
							[
									SAssignNew(VxInPut, SEditableTextBox)
									.Text(FText::FromString(""))
									.Font(FSlateFontInfo("Verdana", 34))
									.HintText(FText::FromString("Enter Vx velocity Here"))
									.OnTextChanged(this, &SMainWidget::OnVelocityXChanged)
							]
					]//borderVx
				]
			+ SVerticalBox::Slot()//Vy
				[
						SNew(SBorder).Padding(FMargin(3))
						.BorderBackgroundColor(FLinearColor::Blue)
						[
								SNew(SHorizontalBox)
								+ SHorizontalBox::Slot()
								[
										SNew(STextBlock)
										.ShadowColorAndOpacity(FLinearColor::Black)
										.ColorAndOpacity(FLinearColor::Red)
										.ShadowOffset(FIntPoint(-1, 1))
										.Font(FSlateFontInfo("Verdana", 34))
										.Text(FText::FromString(" ENTER Vy velocity "))
								]
							+ SHorizontalBox::Slot()
								[
										SAssignNew(VyInPut, SEditableTextBox)
										.Text(FText::FromString(""))
										.Font(FSlateFontInfo("Verdana", 34))
										.HintText(FText::FromString("Enter Vy Here"))
										.OnTextChanged(this, &SMainWidget::OnVelocityYChanged)
								]
						]//borderVy
				]

			+ SVerticalBox::Slot()//Vz
				[
						SNew(SBorder).Padding(FMargin(3))
						.BorderBackgroundColor(FLinearColor::Blue)
						[
								SNew(SHorizontalBox)
								+ SHorizontalBox::Slot()
								[
									SNew(STextBlock)
									.ShadowColorAndOpacity(FLinearColor::Black)
									.ColorAndOpacity(FLinearColor::Red)
									.ShadowOffset(FIntPoint(-1, 1))
									.Font(FSlateFontInfo("Verdana", 34))
									.Text(FText::FromString(" ENTER Vz Velocity "))
								]
							+ SHorizontalBox::Slot()
								[
									SAssignNew(VzInPut, SEditableTextBox)
									.Text(FText::FromString(""))
									.Font(FSlateFontInfo("Verdana", 34))
									.HintText(FText::FromString("Enter Velocity z Here"))
									.OnTextChanged(this, &SMainWidget::OnVelocityZChanged)
								]
						]//borderVz
				]
			+ SVerticalBox::Slot()//additonal button
				[
					
					SNew(SButton)

					[
						SNew(STextBlock)
					]
					
				]
			+ SVerticalBox::Slot()
			[
					SAssignNew(PlayButton, SButton)
					.ButtonStyle(FCoreStyle::Get(), "NoBorder")
					.HAlign(HAlign_Center).VAlign(VAlign_Center)
					.OnClicked(this, &SMainWidget::OnPlayClicked)
					[
							SNew(SBorder).Padding(FMargin(3))
							.BorderBackgroundColor(FLinearColor::Blue)
							[
								SNew(STextBlock)
								.ShadowColorAndOpacity(FLinearColor::Black)
								.ColorAndOpacity(FLinearColor::Red)
								.ShadowOffset(FIntPoint(-1, 1))
								.Font(FSlateFontInfo("Verdana", 34))
								.Text(FText::FromString("RENDER INFO"))
							]
					]
			]
			+ SVerticalBox::Slot()
			[
				SAssignNew(AddNextButton, SButton)
				.ButtonStyle(FCoreStyle::Get(), "NoBorder")
				.HAlign(HAlign_Center).VAlign(VAlign_Center)
				.OnClicked(this, &SMainWidget::OnAddClicked)
					[
						SNew(SBorder).Padding(FMargin(3))
						.BorderBackgroundColor(FLinearColor::Blue)
						[
							SNew(STextBlock)
							.ShadowColorAndOpacity(FLinearColor::Black)
							.ColorAndOpacity(FLinearColor::Red)
							.ShadowOffset(FIntPoint(-1, 1))
							.Font(FSlateFontInfo("Verdana", 34))
							.Text(FText::FromString("ADD NEXT PLANET"))
						]
					]
			]

		];

}
void SMainWidget::OnMassChanged(const FText & InText)
{
}
void SMainWidget::OnXChanged(const FText & InText)
{
}
void SMainWidget::OnYChanged(const FText & InText)
{
}
void SMainWidget::OnZChanged(const FText & InText)
{
}
void SMainWidget::OnVelocityXChanged(const FText & InText)
{
}
void SMainWidget::OnVelocityYChanged(const FText & InText)
{
}
void SMainWidget::OnVelocityZChanged(const FText & InText)
{
}
FReply SMainWidget::OnAddClicked()
{
	return FReply::Handled();
}
FReply SMainWidget::OnPlayClicked()
{
	return FReply::Handled();
}
FReply SMainWidget::OnMoreClicked()
{
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
