// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DataStruct.generated.h"

/**
 * struct to keep the data for the game
	spawn data is an array of structs 
 */

USTRUCT(BlueprintType)
struct FDataStruct 
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Analytics")
	int32 planets_num;

	//instanciate the array of structs for the planets' data

	FDataStruct(){}

};
