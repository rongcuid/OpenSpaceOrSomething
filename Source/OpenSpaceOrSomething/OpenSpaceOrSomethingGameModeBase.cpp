// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenSpaceOrSomethingGameModeBase.h"

class SPlanetNumWidget;
class SMainWidget;
class ASpacePlayerController;
class UDBWrapper;

//is called when the game starts
void AOpenSpaceOrSomethingGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	planets_num = -1;
	message = TEXT("Welcome");

	/*ready the DB stuff */
	Table_Name = "Project"+getTIMESTAMP();
	databaseFile = FPaths::ConvertRelativePathToFull(FPaths::Combine(FPaths::ProjectSavedDir(), DB_Name));
	


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

FString AOpenSpaceOrSomethingGameModeBase::getTIMESTAMP()
{
	FDateTime LOCALEDT = FDateTime::Now();
	FText TimeStamp = FText::AsDateTime(LOCALEDT,
		EDateTimeStyle::Long,     //date
		EDateTimeStyle::Medium ,//time
		FText::GetInvariantTimeZone()
	);
	FString result = TimeStamp.ToString();
	result = result.Replace(TEXT(" "), TEXT(""));
	result = result.Replace(TEXT(":"), TEXT(""));
	result = result.Replace(TEXT(","), TEXT(""));
	return result;
}


FString AOpenSpaceOrSomethingGameModeBase::saveToDB()
{
	//prepare the db
	UDBWrapper* db = NewObject<UDBWrapper>();

	

	if (db->prepare_DB(databaseFile))
	{
		
		if (db->register_DB(databaseFile, DB_Name))
		{
			FString query = "";
			query += "CREATE TABLE IF NOT EXISTS ";
			query += Table_Name;
			query += " (id INTEGER PRIMARY KEY AUTOINCREMENT,"
				"Mass REAL ,"
				"X REAL, "
				"Y REAL," 
				"Z REAL, "
				"Vx REAL, "
				"Vy REAL,"
				"Vz REAL)";
			
			if (db->prepare_Table(DB_Name, Table_Name,query))
			{
				
				
				for (int32 i = 0; i < planets_data.Num(); i++)
				{
					query = "";
					query += "INSERT INTO ";
					query += Table_Name;
					query += " (Mass, X, Y, Z, Vx, Vy, Vz)";
					query += " VALUES (";
					query += FString::SanitizeFloat(planets_data[i].data[0]);
					query += ",";
					query += FString::SanitizeFloat(planets_data[i].data[1]);
					query += ",";
					query += FString::SanitizeFloat(planets_data[i].data[2]);
					query += ",";
					query += FString::SanitizeFloat(planets_data[i].data[3]);
					query += ",";
					query += FString::SanitizeFloat(planets_data[i].data[4]);
					query += ",";
					query += FString::SanitizeFloat(planets_data[i].data[5]);
					query += ",";
					query += FString::SanitizeFloat(planets_data[i].data[6]);
					query += ")";
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, *query);

					
					if (db->insert_intoDB(DB_Name, query))
					{
						GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("inserted data"));
						return TEXT("Success");
					}
				}
				

				
			}
		}

	}
	return (TEXT("ERROR: was not able to save information"));
	
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

