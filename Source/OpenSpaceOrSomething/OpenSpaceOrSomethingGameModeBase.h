// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SMainWidget.h"
#include "SPlanetNumWidget.h"
#include "DataStruct.h"
#include "SlateBasics.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "Widgets/SWeakWidget.h"
#include "SpacePlayerController.h"
#include "Planet.h"
#include "Runtime/Core/Public/Math/TransformNonVectorized.h"
#include "OpenSpaceOrSomethingGameModeBase.generated.h"

class SPlanetNumWidget;

/**
 * AOpenSpaceOrSomethingGameModeBase class for the main game mode
 */
UCLASS()
class OPENSPACEORSOMETHING_API AOpenSpaceOrSomethingGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
		
public:
	/** Remove the current start widget and add dmain info menu another */
	void displayMainMenu(int32 count);
	void setPlanetNum(int32 count);
	void setMessage(FString mes);
	TArray<FPlanetStruct>* getDataPtr();
	void instantiateData(int32 index);

	/** Called when the game starts. */
	virtual void BeginPlay() override;
	void displayStartMenu();

	void renderPlanets();

	//will instantiate the planets with the location in origin(0,0,0)
	void spawnPlanets(int32 num);

	//start widget is the SPlanetNumWidget to get the number of planets
	TSharedPtr<SWidget> StartWidget;

	/** The widget instance that will behave as temp variable */
	TSharedPtr<SWidget> CurrentWidget;

	int32 planets_num;
	FString message;
	TArray<FPlanetStruct> planets_data;
	TArray<APlanet*> planet_ptr;

	
};
