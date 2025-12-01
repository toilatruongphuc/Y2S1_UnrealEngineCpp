// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_0.h"

// Sets default values
ANPC_0::ANPC_0()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANPC_0::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANPC_0::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANPC_0::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
UBehaviorTree* ANPC_0::GetBehaviorTree() const
{
	return Tree;
}

APatrolPath* ANPC_0::GetPatrolPath() const
{
	return PatrolPath;
}
