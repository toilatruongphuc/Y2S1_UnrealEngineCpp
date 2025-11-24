// Fill out your copyright notice in the Description page of Project Settings.

#include "NPC_0_AIController.h"
#include "NPC_0.h"

ANPC_0_AIController::ANPC_0_AIController(FObjectInitializer const& ObjectInitializer)
{
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
