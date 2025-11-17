// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPickUpGameMode.h"

#include "GameFramework/PlayerStart.h"
#include "Kismet/GameplayStatics.h"
#include "Y2S1_Project1/Y2S1_Project1Character.h"

AMyPickUpGameMode::AMyPickUpGameMode()
{
	_CountdownTimer = 3;	
}

AActor* AMyPickUpGameMode::FindPlayerStart_Implementation(AController* Player, const FString& IncomingName)
{
	if (_PlayerStarts.Num() == 0)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerStart::StaticClass(), _PlayerStarts);
	}
	if (_PlayerStarts.Num() > 0)
	{
		return _PlayerStarts[0];
	}
	return nullptr;
}

void AMyPickUpGameMode::PostLogin(APlayerController* NewPlayer)
{
	_PlayerControllers.AddUnique(NewPlayer);
	if (AY2S1_Project1Character* castedPC = Cast<AY2S1_Project1Character>(NewPlayer))
	{
		castedPC->Init();
	}
	Cast<APlayerController>(NewPlayer);
	Super::PostLogin(NewPlayer);
}

void AMyPickUpGameMode::Logout(AController* Exiting)
{
	_PlayerControllers.Remove(Exiting);
	Super::Logout(Exiting);
}

void AMyPickUpGameMode::DecreaseCountDown()
{
	_CountdownTimer--;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT("%d"), _CountdownTimer));
	if (_CountdownTimer <= 0)
	{
		StartMatch();
	}
	else
	{
		GetWorld()->GetTimerManager().SetTimer(_TimerDecreaseCountdown, this, &AMyPickUpGameMode::DecreaseCountDown, 1.f, false);		
	}
}

void AMyPickUpGameMode::HandleMatchIsWaitingToStart()
{
	GetWorld()->GetTimerManager().SetTimer(_TimerDecreaseCountdown, this, &AMyPickUpGameMode::DecreaseCountDown, 1.f, false);
	Super::HandleMatchIsWaitingToStart();
}

void AMyPickUpGameMode::HandleMatchHasStarted()
{
	for (AController* controller : _PlayerControllers)
	{
		//defensive coding
		if (UKismetSystemLibrary::DoesImplementInterface(controller, UMatchStateHandler::StaticClass()))
		{
			IMatchStateHandler::Execute_Handle_MatchStarted(controller);
		}
	}
	Super::HandleMatchHasStarted();
}

void AMyPickUpGameMode::HandleMatchHasEnded()
{for (AController* controller : _PlayerControllers)
{
	//defensive coding
	if (UKismetSystemLibrary::DoesImplementInterface(controller, UMatchStateHandler::StaticClass()))
	{
		IMatchStateHandler::Execute_Handle_MatchEnded(controller);
	}
}
	Super::HandleMatchHasEnded();
}

void AMyPickUpGameMode::OnMatchStateSet()
{
	FString output;
	if (MatchState == MatchState::WaitingToStart)
	{
		output = "Waiting To Start";
	}
	else if (MatchState == MatchState::InProgress)
	{
		output = "In Progress";
	}
	else if (MatchState == MatchState::WaitingPostMatch)
	{
		output = "Wait Post Match";
	}
	else if (MatchState == MatchState::LeavingMap)
	{
		output = "Leaving Map";
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Turquoise, FString::Printf(TEXT("%s"), *output));
	
	Super::OnMatchStateSet();
}

bool AMyPickUpGameMode::ReadyToStartMatch_Implementation()
{
	return false;
//	return Super::ReadyToStartMatch_Implementation();
}

bool AMyPickUpGameMode::ReadyToEndMatch_Implementation()
{
	return false;
	//return Super::ReadyToEndMatch_Implementation();
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
