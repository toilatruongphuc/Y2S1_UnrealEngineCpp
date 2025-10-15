// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FirstInterface.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "SecondActor.generated.h"

UCLASS()
class Y2S1_PROJECT1_API ASecondActor : public AActor, public IFirstInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASecondActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<USceneComponent> Root;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> Box;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// virtual void Interact_Implementation() override;
};
