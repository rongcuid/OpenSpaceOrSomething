// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SQLiteDatabase.h"

#include "DBWrapper.generated.h"

/**
 * class DBWrapper will wrap the DB pluggin
 */
UCLASS()
class OPENSPACEORSOMETHING_API UDBWrapper : public UObject
{
	GENERATED_BODY()

public:
	void set_DB(FString db_name);
	FString DB_Name;
	
	
	
};
