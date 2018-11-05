// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DataStruct.generated.h"

/**
 * struct to keep the data for the tables in the database
 
 */

USTRUCT(BlueprintType)
struct FDBTable
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Analytics")
    FString tabel_name;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Analytics")
	int32 planet_id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Analytics")
	FString project_name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Analytics")
	int32 mass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Analytics")
	int32 x;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Analytics")
	int32 y;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Analytics")
	int32 z;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Analytics")
	int32 Vx;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Analytics")
	int32 Vy;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Analytics")
	int32 vz;

	//instanciate the array of structs for the planets' data



};

USTRUCT(BlueprintType)
struct FDBTableFilds
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Analytics")
		TArray<FString> Fields;

	FDBTableFilds()
	{
		Fields.Emplace(TEXT("planet_id"));
		Fields.Emplace(TEXT("x"));
		Fields.Emplace(TEXT("y"));
		Fields.Emplace(TEXT("z"));
		Fields.Emplace(TEXT("Vx"));
		Fields.Emplace(TEXT("Vy"));
		Fields.Emplace(TEXT("Vz"));
		Fields.Emplace(TEXT("project_name"));
	}


};


USTRUCT(BlueprintType)
struct FPlanetStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Analytics")
		TArray<float> data;


	FPlanetStruct() 
	{
		data.Init(0, 7);
	}



};