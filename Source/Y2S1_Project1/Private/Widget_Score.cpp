// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget_Score.h"

#include "Components/TextBlock.h"

void UWidget_Score::NativeConstruct()
{
	Super::NativeConstruct();

	if (ScoreText != nullptr)
	{
		ScoreText->SetText(FText::FromString("Score"));
	}
}
void UWidget_Score::UpdateScore(int score)
{
	if (ScoreText != nullptr)
	{
		
	}
}
