// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"
#include "Widget_Score.h"
#include "TestWidget.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "Y2S1_Project1/Y2S1_Project1Character.h"

AMyPlayerController::AMyPlayerController()
{
	
}

void AMyPlayerController::Init_Implementation()
{
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}
	// defensive coding
	if (GetPawn() != nullptr)
	{
		GetPawn()->Destroy();
	}
	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UWidget_Score, AMyPlayerController*>(this, HUDWidgetClass);
		HealthBar = CreateWidget<UWidget_Score, AMyPlayerController*>(this, HUDWidgetClass);
	}
	// If the widget exists then add it to viewport
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->AddToViewport();
	}
	
}

void AMyPlayerController::Handle_MatchStarted_Implementation()
{
	UWorld* const World = GetWorld();

	AActor* tempStart = UGameplayStatics::GetGameMode(World)->FindPlayerStart(this);
	FVector spawnLocation = tempStart != nullptr ? tempStart->GetActorLocation() : FVector::ZeroVector;
	FRotator spawnRotation = tempStart != nullptr ? tempStart->GetActorRotation() : FRotator::ZeroRotator;
	FActorSpawnParameters spawnParams;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	APawn* tempPawn = World->SpawnActor<APawn>(PawntoPawn, spawnLocation, spawnRotation, spawnParams);
	Possess(tempPawn);
	UE_LOG(LogTemp, Warning, TEXT("possesed"));
	if (AY2S1_Project1Character* castedPawn = Cast<AY2S1_Project1Character>(tempPawn))
	{
		//bind to any relevant events
		castedPawn->Init();
	}
	
}

void AMyPlayerController::Handle_MatchEnded_Implementation()
{
	IMatchStateHandler::Handle_MatchEnded_Implementation();
}



// Before Init lesson, if needed, uncomment this to make the code work again
// void AMyPlayerController::BeginPlay()
// {
// 	Super::BeginPlay();
//
// 	//Create new Widget
// 	if (HUDWidgetClass != nullptr)
// 	{
// 		CurrentWidget = CreateWidget<UWidget_Score, AMyPlayerController*>(this, HUDWidgetClass);
// 		HealthBar = CreateWidget<UWidget_Score, AMyPlayerController*>(this, HUDWidgetClass);
// 	}
// 	// If the widget exists then add it to viewport
// 	if (CurrentWidget != nullptr)
// 	{
// 		CurrentWidget->AddToViewport();
// 	}
// }
// void AMyPlayerController::AddScore(int amount)
// 	{
// 		_Score += amount;
// 		if (CurrentWidget != nullptr)
// 		{
// 			UE_LOG(LogTemp, Log, TEXT("Score: %d"), _Score);
// 			CurrentWidget->UpdateScore(_Score);
// 		}
// 	}
// 	void AMyPlayerController::GetHealthPercentage(float currentHealth, float maxHealth)
// {
// 	if (CurrentWidget != nullptr)
// 	{
// 		float result = 0; 
// 		result = (currentHealth / maxHealth) * 100;
// 		_HealthPercentage = result;
// 	}
// }
