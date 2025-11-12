// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPickUpGameMode.h"

#include "Kismet/GameplayStatics.h"

AMyPickUpGameMode::AMyPickUpGameMode()
{
	
}

AActor* AMyPickUpGameMode::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
{
	return Super::FindPlayerStart_Implementation(Player, IncomingName);
}

void AMyPickUpGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}

void AMyPickUpGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
}

void AMyPickUpGameMode::DecreaseCountDown()
{
}

void AMyPickUpGameMode::HandleMatchIsWaitingToStart()
{
	Super::HandleMatchIsWaitingToStart();
}

void AMyPickUpGameMode::HandleMatchHasStarted()
{
	Super::HandleMatchHasStarted();
}

void AMyPickUpGameMode::HandleMatchHasEnded()
{
	Super::HandleMatchHasEnded();
}

void AMyPickUpGameMode::OnMatchSucceeded()
{
}

bool AMyPickUpGameMode::ReadyToStartMatch_Implementation()
{
	return Super::ReadyToStartMatch_Implementation();
}

bool AMyPickUpGameMode::ReadyToEndMatch_Implementation()
{
	return Super::ReadyToEndMatch_Implementation();
}

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
void AMyPickUpGameMode::GivePlayerScore(int score, AMyPlayerController* PickerUp)
{
	if (AMyPlayerController* castedPC = Cast <AMyPlayerController>(PickerUp))
	{
		UE_LOG(LogTemp, Display, TEXT("Give %s: %d"), *PickerUp->GetName(), score);
		castedPC->AddScore(score);
	}
	if (PickerUp->GetScore() >= 1000)
	{
		UE_LOG(LogTemp, Display, TEXT("You Won!"));
	}
	
}
