// Fill out your copyright notice in the Description page of Project Settings.

#include "DBWrapper.h"


/*checks if the DB_file exists already and if not, it creates it*/
bool UDBWrapper::prepare_DB(FString db_filepath)
{
	//checks if the file exists and creates if it does not, it creates a file
	if (!USQLiteDatabase::IsValidDatabase(db_filepath, false))
	{
		if (!USQLiteDatabase::CreateDatabase(db_filepath, false)) 
		{
			
			UE_LOG(LogTemp, Error, TEXT("Couldn't create database %s"), *db_filepath);
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("it could not save the file. Try again later."));
			return false;
		}
		UE_LOG(LogTemp, Log, TEXT("Created database %s"), *db_filepath);
	}

	return true;
}

/*checks if the db regidtered and if not registers it*/
bool UDBWrapper::register_DB(FString db_filepath, FString db_name)
{
	//check if db is restered
	if (!USQLiteDatabase::IsDatabaseRegistered(db_name))
	{
		//register the db
		if (!USQLiteDatabase::RegisterDatabase(db_name, db_filepath, false, true))
		{
			UE_LOG(LogTemp, Error, TEXT("Couldn't register database %s"), *db_filepath);
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("it could not register db. Try again later."));
			
			return false;
		}
		UE_LOG(LogTemp, Error, TEXT("Registered database %s"), *db_filepath);
	}
	return true;
}
	
		
/*checks if the table exists and creates it if it is not */
bool UDBWrapper::prepare_Table(FString db_name, FString table_name, const FString& Query)
{
	//check if the table exists
	if (!USQLiteDatabase::IsTableExists(db_name, table_name))
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("checked if table exists"));
		//add table
		bool success = USQLiteDatabase::ExecSql(db_name, Query);

			if (!success) {
				UE_LOG(LogTemp, Error, TEXT("Couldn't create table"));
				GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("did not create table"));
				return false;
			}
	}
	UE_LOG(LogTemp, Error, TEXT("Created table"));
	return true;
}


bool UDBWrapper::insert_intoDB(FString db_name, const FString& Query)
{
	bool success = USQLiteDatabase::ExecSql(db_name, Query);

	if (!success) {
		UE_LOG(LogTemp, Error, TEXT("Couldn't create table"));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("could not insert data into table"));
		return false;
	}

	return true;
}

void UDBWrapper::updateDB()
{
}

void UDBWrapper::delete_fromDB()
{
}

void UDBWrapper::readyDBFields()
{
	db_fields.Add("Mass");//0
	db_fields.Add("X");//1
	db_fields.Add("Y");//2
	db_fields.Add("Z");//3
	db_fields.Add("Vx");//4
	db_fields.Add("Vy");//5
	db_fields.Add("Vz");//6

}

void UDBWrapper::populateFSQLiteTableField()
{
	table_data[0].ResultStr = "PRIMARY KEY ASC";

	for (int32 i = 0; i < 6; i++)
	{
		table_data[i].FieldName = db_fields[i];
		table_data[i].FieldType = "REAL";
	}

}
