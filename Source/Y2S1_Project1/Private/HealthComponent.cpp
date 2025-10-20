// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "Runtime/Core/Private/Android/AndroidPlatformManualResetEvent.h"


// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	_MaxHealth = 100.0f;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
_CurrentHealth = _MaxHealth;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);
	
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                     FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
void UHealthComponent::DamageTaken(AActor* damagedActor, float damage, const UDamageType* damageType,
	AController* instigator, AActor* causer)
{
	const float change = FMath::Min(_CurrentHealth, damage); 
	_CurrentHealth -= change; 

	UE_LOG(LogTemp, Display, TEXT("Damaged for %f, %f health remaining"), change, _CurrentHealth); 

	if (_CurrentHealth == 0.0f) {
		UE_LOG(LogTemp, Display, TEXT("Dead")); 
	}
}

