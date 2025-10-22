// Fill out your copyright notice in the Description page of Project Settings.


#include "pickupActor.h"


// Sets default values
ApickupActor::ApickupActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("ROOT"));
	RootComponent = Root;
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Root);
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	BoxComponent->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void ApickupActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ApickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
void ApickupActor::Pickup_Implementation(AActor* PickerUp)
{
	PickUpDelegate.Broadcast(PickUpScore, PickerUp);
	Destroy();
}

