// Fill out your copyright notice in the Description page of Project Settings.

#include "Planet.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"


// Sets default values
APlanet::APlanet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SphereComponent->InitSphereRadius(40.0f);

	Mesh_Shape = CreateDefaultSubobject<UStaticMeshComponent>("Mesh_Shape");
	RootComponent = SphereComponent;
	Mesh_Shape->SetupAttachment(RootComponent);

	auto MeshAsset =
		ConstructorHelpers::FObjectFinder<UStaticMesh>(TEXT("StaticMesh'/Engine/BasicShapes/Cube.Cube'"));

	if (MeshAsset.Object != nullptr)
	{
		Mesh_Shape->SetStaticMesh(MeshAsset.Object);
		Mesh_Shape->SetRelativeLocation(FVector(0.0f, 0.0f, -40.0f));
		Mesh_Shape->SetWorldScale3D(FVector(0.8f));
	}

	
}

// Called when the game starts or when spawned
void APlanet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlanet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

AActor * APlanet::getPlanetPtr()
{
	return this;
}

