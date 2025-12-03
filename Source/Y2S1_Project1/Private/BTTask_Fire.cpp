// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Fire.h"

#include "NPC_0.h"
#include "NPC_0_AIController.h"

UBTTask_Fire::UBTTask_Fire(FObjectInitializer const& ObjectInitializer)
{
	
}

EBTNodeResult::Type UBTTask_Fire::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	if (auto* const cont = Cast<ANPC_0_AIController>(OwnerComp.GetAIOwner()))
	{
		if (auto* npc = Cast<ANPC_0>(cont->GetPawn()))
		{
			npc->OnFire();

			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}
