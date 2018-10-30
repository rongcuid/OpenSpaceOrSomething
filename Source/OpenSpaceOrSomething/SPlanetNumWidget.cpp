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
						.HintText(FText::FromString(" "))
						//.OnTextChanged(this, &SPlanetNumWidget::OnAddTextChanged)
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
/*
void SPlanetNumWidget::OnAddTextChanged(const FText & InText)
{
}

*/
//TODO: validation !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
FReply SPlanetNumWidget::OnStartClicked()
{

	//get the number of planets from the textbox
	FText out = NumberInPut->GetText();
	FString temp;

	if (!out.IsEmptyOrWhitespace())
	{
		//validate with the c++
		//convert form a double in c ++ into Fstring in unreal engine
		// static FString SanitizeFloat( double InFloat );

		//convet from the Fstring into c++ string
		// std::string test2 = std::string(TCHAR_TO_UTF8(*test));

	   //from std::string into FString
	   //FString(StringC++.c_str())

		temp = out.ToString();

		int32 num = FCString::Atoi(*temp);

		


		//hardcoded 5, change the mesage to format the number of planets
		parent->displayMainMenu(num, this, "you have this many planets to enter into for ");
		
	}
	else
	{
		prompt = TEXT("DO NOT FORGET TO ENTER THE NUMBER ");
		parent->redisplayMenu(prompt,0);
	}
	
	return FReply::Handled();
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION
