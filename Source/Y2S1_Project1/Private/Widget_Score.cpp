// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget_Score.h"

#include "Components/TextBlock.h"

void UWidget_Score::NativeConstruct()
{
	Super::NativeConstruct();

	if (ScoreText != nullptr)
	{
		ScoreText->SetText(FText::FromString("Score: 0"));
	}
}
void UWidget_Score::UpdateScore(int score)
{
	if (ScoreText != nullptr && score < 1000)
	{
		UE_LOG(LogTemp, Log, TEXT("Called"));
		ScoreText->SetText(FText::FromString(FString::Printf(TEXT("Score: %d"), score)));
	}
	else
	{
		ScoreText->SetText(FText::FromString("Won!"));
	}
}
