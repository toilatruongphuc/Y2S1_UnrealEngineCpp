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

	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta=(AllowPrivateAccess = "true"))
	// UInputAction* DecreaseHealthAction;
	//
	// UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta=(AllowPrivateAccess = "true"))
	// UInputAction* IncreaseHealthAction;
public:
	int GetScore(){return _Score;};
	void AddScore(int amount);

	void GetHealthPercentage(float currentHealth, float maxHealth);
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Input")
	class UInputMappingContext* DefaultMappingContext;

	virtual void BeginPlay() override;
//void DecreaseHealth(const FInputActionValue& Value);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = UI)
	TSubclassOf<UWidget_Score> HUDWidgetClass;

	UPROPERTY()
	UWidget_Score* CurrentWidget;

	UPROPERTY()
	UWidget_Score* HealthBar;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameStats)
	int _Score = 0;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameStats)
	float CurrentHealth = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameStats)
	float MaxHealth = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameStats)
	float _HealthPercentage;
	UPROPERTY(EditAnywhere)
	TSubclassOf<UWidget_Score> ScoreWidgetClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UWidget_Score> HealthWidgetClass;
};
