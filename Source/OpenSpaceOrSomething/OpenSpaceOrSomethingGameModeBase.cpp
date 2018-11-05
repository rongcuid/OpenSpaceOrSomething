// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenSpaceOrSomethingGameModeBase.h"

class SPlanetNumWidget;
class SMainWidget;
class ASpacePlayerController;

//is called when the game starts
void AOpenSpaceOrSomethingGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	planets_num = -1;
	message = TEXT("Welcome to the Game");


	//set the ASpaceController class as a default player controller class for this gamemode
	PlayerControllerClass = ASpacePlayerController::StaticClass();
	
	displayStartMenu();
	
}


void AOpenSpaceOrSomethingGameModeBase::displayStartMenu()
{
	StartWidget = SNew(SPlanetNumWidget).messageArg(message).ownerArg(this);
	if (GEngine)
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(StartWidget.ToSharedRef()));
	}

	StartWidget->SetVisibility(EVisibility::Visible);

}

void AOpenSpaceOrSomethingGameModeBase::renderPlanets()
{
	spawnPlanets(planets_num);
}

//MUST ADD ASSERTIONS ,CHECK FOR THE NULL PTRs
void AOpenSpaceOrSomethingGameModeBase::displayMainMenu(int32 redisplay_count)
{

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("will be moving to the main"));
	}

	//build the mainmenu widget and display it
	CurrentWidget = SNew(SMainWidget).messageArg(message).ownerArg(this).countArg(redisplay_count);

	if (GEngine)
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(CurrentWidget.ToSharedRef()));
	}

	CurrentWidget->SetVisibility(EVisibility::Visible);
	
}

void AOpenSpaceOrSomethingGameModeBase::setPlanetNum(int32 count)
{
	planets_num = count;
	instantiateData(count);
}

void AOpenSpaceOrSomethingGameModeBase::setMessage(FString mes)
{
	message = mes;
}

TArray<FPlanetStruct>* AOpenSpaceOrSomethingGameModeBase::getDataPtr()
{
	return &planets_data;
}

void AOpenSpaceOrSomethingGameModeBase::instantiateData(int32 index)
{
	
	for (int32 i = 0; i < index; i++)
	{
		planets_data.Add(FPlanetStruct());
	}
}

void AOpenSpaceOrSomethingGameModeBase::spawnPlanets(int32 num)
{
	
	for (int32 i = 0; i < num; i++)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("inside the methods loop spawning"));
		if (GetWorld())
		{
			planet_ptr.Add( GetWorld()->SpawnActor<APlanet>(APlanet::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator));

		}

	}
	
}

