// Fill out your copyright notice in the Description page of Project Settings.

/*the menu for the main data collection for a planet*/

#include "SMainWidget.h"
#include "SlateOptMacros.h"
#include <string>
#include "Runtime/Engine/Classes/Engine/Engine.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainWidget::Construct(const FArguments& InArgs)
{
	prompt = InArgs._messageArg;
	parent = InArgs._ownerArg;///gamemode pointer
	redisplay_count = InArgs._countArg;

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
			//.Padding(FMargin(520.0f, 20.0f, 520.0f, 50.0f))
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
								//.OnTextChanged(this, &SMainWidget::OnMassChanged)
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
								//.OnTextChanged(this, &SMainWidget::OnXChanged)
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
								//.OnTextChanged(this, &SMainWidget::OnYChanged)
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
								//.OnTextChanged(this, &SMainWidget::OnZChanged)
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
									//.OnTextChanged(this, &SMainWidget::OnVelocityXChanged)
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
										//.OnTextChanged(this, &SMainWidget::OnVelocityYChanged)
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
									//.OnTextChanged(this, &SMainWidget::OnVelocityZChanged)
								]
						]//borderVz
				]
			+ SVerticalBox::Slot()//additonal button
				[
					
					SAssignNew(SaveButton, SButton)
					.ButtonStyle(FCoreStyle::Get(), "NoBorder")
					.HAlign(HAlign_Center).VAlign(VAlign_Center)
					.OnClicked(this, &SMainWidget::OnSaveClicked)
					[
							SNew(SBorder).Padding(FMargin(3))
							.BorderBackgroundColor(FLinearColor::Blue)
							[
								SNew(STextBlock)
								.ShadowColorAndOpacity(FLinearColor::Black)
								.ColorAndOpacity(FLinearColor::Red)
								.ShadowOffset(FIntPoint(-1, 1))
								.Font(FSlateFontInfo("Verdana", 34))
								.Text(FText::FromString("SAVE INFO"))
							]
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
							.Text(FText::FromString(("ADD "+ FString::FromInt(redisplay_count)+ " PLANETs")))
						]
					]
			]

		];

}

/*
void SMainWidget::OnMassChanged(const FText & InText)
{

	FString temp;
	std::string C_String;
	FString result;
	
	temp = MassInPut->GetText().ToString();

	//convert form a double in c ++ into Fstring in unreal engine
	// static FString SanitizeFloat( double InFloat );
	
	//convet from the Fstring into c++ string
	// std::string test2 = std::string(TCHAR_TO_UTF8(*test));

	//from std::string into FString
	//FString(StringC++.c_str())

	C_String = std::string(TCHAR_TO_UTF8(&temp));

	//do the c++ validation
	//maybe get the error message from the validation

	result = FString(C_String.c_str());
	
	

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

*/

//validate and add the information into the planets_data
//redisplay the menu 
FReply SMainWidget::OnAddClicked()
{
	TArray<FPlanetStruct>* dataArray = parent->getDataPtr();
	int32 index = redisplay_count - 1;

	//validate the data
	//spawn an actor from the gamemode if data is ok
	//get the data from the textboxes
	FString temp = MassInPut->GetText().ToString();
	dataArray->GetData()[index].data[0] = FCString::Atof(*temp);

	FString TheFloatStr = FString::SanitizeFloat(dataArray->GetData()[index].data[0]);
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, *TheFloatStr);
	}


	temp = XInPut->GetText().ToString();
	float x = FCString::Atof(*temp);
	dataArray->GetData()[index].data[1] = FCString::Atof(*temp);

	temp = YInPut->GetText().ToString();
	float y = FCString::Atof(*temp);
	dataArray->GetData()[index].data[2] = FCString::Atof(*temp);

	temp = ZInPut->GetText().ToString();
	float z = FCString::Atof(*temp);
	dataArray->GetData()[index].data[3] = FCString::Atof(*temp);

	temp = VxInPut->GetText().ToString();
	float Vx = FCString::Atof(*temp);
	dataArray->GetData()[index].data[4] = FCString::Atof(*temp);

	temp = VyInPut->GetText().ToString();
	float Vy = FCString::Atof(*temp);
	dataArray->GetData()[index].data[5] = FCString::Atof(*temp);

	temp = VzInPut->GetText().ToString();
	float Vz = FCString::Atof(*temp);
	dataArray->GetData()[index].data[6] = FCString::Atof(*temp);
	
	if ((redisplay_count - 1) != 0)
	{
		parent->displayMainMenu(redisplay_count-1);
	}
	

	

	
	//redisplay the menu for the next data collection
	return FReply::Handled();
}

//render info button
FReply SMainWidget::OnPlayClicked()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("clicked to render the planets button"));
	this->SetVisibility(EVisibility::Collapsed);
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("after the render method"));
	parent->renderPlanets();
	return FReply::Handled();
}

//save the infomaion to the db
FReply SMainWidget::OnSaveClicked()
{
	FString result = parent->saveToDB();
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, *result);
	return FReply::Handled();
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
