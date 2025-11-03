// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Blueprint/UserWidget.h"
#include "Widget_Score.generated.h"
/**
 * 
 */
class UTextBlock;
UCLASS(Abstract, BlueprintType)
class Y2S1_PROJECT1_API UWidget_Score : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	void UpdateScore(int score);

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> ScoreText;

	
};
