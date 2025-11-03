// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FirstInterface.h"
#include "MyPlayerController.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "pickupActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FpickupActorDelegate, int, PickupScore, AMyPlayerController*, Pickerup );
UCLASS()
class Y2S1_PROJECT1_API ApickupActor : public AActor, public IFirstInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ApickupActor();
	virtual void Pickup_Implementation(AMyPlayerController* PickerUp) override;

	
	int GetPickUpScore()
	{
		return PickUpScore;
	}
	FpickupActorDelegate PickUpDelegate;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<USceneComponent> Root;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UStaticMeshComponent> StaticMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> BoxComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int PickUpScore;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
