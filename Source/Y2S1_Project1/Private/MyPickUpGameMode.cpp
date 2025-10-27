// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPickUpGameMode.h"

#include "Kismet/GameplayStatics.h"

void AMyPickUpGameMode::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> PickUpActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ApickupActor::StaticClass(), PickUpActors);

	for (AActor* Actor : PickUpActors)
	{
		ApickupActor* Pickup = Cast<ApickupActor>(Actor);

		Pickup->PickUpDelegate.AddDynamic(this, &AMyPickUpGameMode::GivePlayerScore);
		UE_LOG(LogTemp, Display, TEXT("Test"));
	}
}
void AMyPickUpGameMode::GivePlayerScore(int score, AActor* PickerUp)
{
	UE_LOG(LogTemp, Display, TEXT("Give %s: %d"), *PickerUp->GetName(), score);
}
