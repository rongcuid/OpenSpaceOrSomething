// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SQLiteDatabase.h"
#include "SQLiteDatabaseStructs.h"

#include "DBWrapper.generated.h"

/**
 * class DBWrapper will wrap the DB pluggin
 */
UCLASS()
class OPENSPACEORSOMETHING_API UDBWrapper : public UObject
{
	GENERATED_BODY()

public:
	
	bool prepare_DB(FString db_filepath);
	bool register_DB(FString db_filepath, FString db_name);
	bool prepare_Table(FString db_name, FString table_name, const FString& Query);

	bool insert_intoDB(FString db_name, const FString& Query);
	void updateDB();
	void delete_fromDB();

	void readyDBFields();
	void populateFSQLiteTableField();

	TArray<FString> db_fields;
	TArray< FSQLiteTableField> table_data;
	FString table_name;
	FString db_name;
	
};
