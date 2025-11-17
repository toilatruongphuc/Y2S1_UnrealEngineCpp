// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
// #include "MyPlayerController.h"
#include "pickupActor.h"
#include "GameFramework/GameMode.h"
#include "MyPickUpGameMode.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class Y2S1_PROJECT1_API AMyPickUpGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	AMyPickUpGameMode();

	virtual AActor* FindPlayerStart_Implementation(AController* Player, const FString& IncomingName) override;

	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void Logout(AController* Exiting) override;
	
	
protected:
	TArray<TObjectPtr<AActor>> _PlayerStarts;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<AController>> _PlayerControllers;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=MatchManagement)
	int _CountdownTimer;

	FTimerHandle _TimerDecreaseCountdown;
	UFUNCTION()
	void DecreaseCountDown();
	
	virtual void BeginPlay() override;

	virtual void HandleMatchIsWaitingToStart() override;
	virtual void HandleMatchHasStarted() override;
	virtual void HandleMatchHasEnded() override;

	virtual void OnMatchStateSet() override;
	
	virtual bool ReadyToStartMatch_Implementation() override;
	virtual bool ReadyToEndMatch_Implementation() override;
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PickUp")
	ApickupActor* PickupActor;

	UFUNCTION()
	void GivePlayerScore(int score, AMyPlayerController* PickerUp);

	
};
