// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC_0_AIController.h"
#include "NPC_0.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Y2S1_Project1/Y2S1_Project1Character.h"

ANPC_0_AIController::ANPC_0_AIController(FObjectInitializer const& ObjectInitializer)
{
	SetupPerceptionSystem();
}
void ANPC_0_AIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (ANPC_0* const npc = Cast<ANPC_0>(InPawn))
	{
		if (UBehaviorTree* const tree = npc->GetBehaviorTree())
		{
			UBlackboardComponent* b;
			UseBlackboard(tree->BlackboardAsset, b);
			Blackboard = b;
			RunBehaviorTree(tree);
		}
	}
}

void ANPC_0_AIController::SetupPerceptionSystem()
{
	AISightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>("Sight Config");
	if (AISightConfig)
	{
		SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));
		AISightConfig->SightRadius = 500.0f;
		AISightConfig->LoseSightRadius = AISightConfig->SightRadius + 25.0f;
		AISightConfig->PeripheralVisionAngleDegrees = 90.0f;
		AISightConfig->SetMaxAge(5.0f);
		AISightConfig->AutoSuccessRangeFromLastSeenLocation = 520.0f;
		AISightConfig->DetectionByAffiliation.bDetectEnemies = true;
		AISightConfig->DetectionByAffiliation.bDetectFriendlies = true;
		AISightConfig->DetectionByAffiliation.bDetectNeutrals = true;

		GetPerceptionComponent()->SetDominantSense(*AISightConfig->GetSenseImplementation());
		GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &ANPC_0_AIController::OnTargetDetected);
		GetPerceptionComponent()->ConfigureSense(*AISightConfig);
	}
}

void ANPC_0_AIController::OnTargetDetected(AActor* Actor, FAIStimulus const Stimulus)
{
	if (auto* const npc = Cast<AY2S1_Project1Character>(Actor))
	{
		GetBlackboardComponent()->SetValueAsBool("CanSeePlayer", Stimulus.WasSuccessfullySensed());
	}
}
