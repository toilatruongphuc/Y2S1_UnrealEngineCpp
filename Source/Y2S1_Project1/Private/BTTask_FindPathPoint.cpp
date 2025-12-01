// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_FindPathPoint.h"

#include "NPC_0.h"
#include "NPC_0_AIController.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTTask_FindPathPoint::UBTTask_FindPathPoint(FObjectInitializer const& ObjectInitializer)
{
	NodeName = "Find Path Point";
}

EBTNodeResult::Type UBTTask_FindPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//attemp to get NPC_0's controller
	if (auto* const cont = Cast<ANPC_0_AIController>(OwnerComp.GetAIOwner()))
	{
		//attempt to get the blackboard component from the behaviour tree
		if (auto* const bc = OwnerComp.GetBlackboardComponent())
		{
			//get the current patrol path index from the blackboard
			auto const index = bc->GetValueAsInt(GetSelectedBlackboardKey());

			//get the NPC
			if (auto* npc = Cast<ANPC_0>(cont->GetPawn()))
			{
				//get the current patrol path vector from the NPC - this is local to the patrol path actor
				auto const Path = npc->GetPatrolPath()->GetPatrolPoint(index);
			}
			
		}
	}
	return Super::ExecuteTask(OwnerComp, NodeMemory);
}
