// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

#include "EnhancedInputSubsystems.h"

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(DefaultMappingContext, 0);
	}

	//Create new Widget
	CurrentWidget = CreateWidget<UTestWidget, AMyPlayerController*>(this, HUDWidgetClass.Get());

	// If the widget exists then add it to viewport
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->AddToViewport();
	}
	
}
