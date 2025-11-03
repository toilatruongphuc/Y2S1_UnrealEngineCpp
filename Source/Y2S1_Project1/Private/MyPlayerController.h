// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TestWidget.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
class UWidget_Score;
UCLASS()
class Y2S1_PROJECT1_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	int GetScore(){return _Score;};
	void AddScore(int amount);
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Input")
	class UInputMappingContext* DefaultMappingContext;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI)
	TSubclassOf<UWidget_Score> HUDWidgetClass;

	UPROPERTY()
	UWidget_Score* CurrentWidget;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameStats)
	int _Score = 0;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UWidget_Score> ScoreWidgetClass;

	
};
