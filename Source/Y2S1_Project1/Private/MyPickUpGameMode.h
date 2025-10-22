// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyPickUpGameMode.generated.h"

/**
 * 
 */
UCLASS()
class Y2S1_PROJECT1_API AMyPickUpGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	
	protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PickUp")
	AFirstPickUp* PickupActor;
};
