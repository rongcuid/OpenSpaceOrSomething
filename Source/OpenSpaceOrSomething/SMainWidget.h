// Fill out your copyright notice in the Description page of Project Settings.

/*the class MainWidget will impement the main menu; inherits from a Compond Slata Widget*/
#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 * main menu widget 
 */
class OPENSPACEORSOMETHING_API SMainWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SMainWidget)
	{}
	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
};
