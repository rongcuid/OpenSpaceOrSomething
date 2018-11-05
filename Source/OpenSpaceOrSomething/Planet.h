// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Runtime/Core/Public/Math/TransformNonVectorized.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Planet.generated.h"

/*Planet class */

UCLASS()
class OPENSPACEORSOMETHING_API APlanet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlanet();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void updatePlanet();

	AActor* getPlanetPtr();
	FTransform SpawnLocation;

	//the main component that will allow the rotation
	//scaling and location of the class
	//the rest of components will be attached to it
	//reaction to physics
	UPROPERTY()
		USphereComponent* SphereComponent;

	//sphere shape for a planet
	//static mesh component for visual rendering
	UPROPERTY()
	UStaticMeshComponent* Mesh_Shape;

	

	
	
};
