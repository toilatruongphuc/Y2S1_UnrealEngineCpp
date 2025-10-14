// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MaterialHLSLTree.h"
#include "GameFramework/Actor.h"
#include "GameFramework/RotatingMovementComponent.h"
#include "FirstActor.generated.h"

class UArrowComponent;

UCLASS(Abstract)
class Y2S1_PROJECT1_API AFirstActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFirstActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly);
	TObjectPtr<USceneComponent> _Root;
	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	TObjectPtr<UStaticMeshComponent> _Mesh;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite);
	TObjectPtr<UArrowComponent> _Arrow;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite);
	TObjectPtr<URotatingMovementComponent> _Rotating;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
