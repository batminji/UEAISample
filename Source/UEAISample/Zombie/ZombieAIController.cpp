// Fill out your copyright notice in the Description page of Project Settings.


#include "ZombieAIController.h"
#include "Zombie.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "../UEAISampleCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"

AZombieAIController::AZombieAIController()
{
	Perception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));

	// 이 기능은 블루프린트로 하는 것이 편하다.
	UAISenseConfig_Sight* SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	SightConfig->SightRadius = 1000.0f;
	SightConfig->LoseSightRadius = 1200.0f;
	SightConfig->PeripheralVisionAngleDegrees = 90.0f;

	// 이 기능은 C++에서만 사용할 수 있으며, 블루프린트에서는 사용할 수 없다.
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = false;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = false;

	Perception->ConfigureSense(*SightConfig);
	Perception->SetDominantSense(*SightConfig->GetSenseImplementation());
}

void AZombieAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	AZombie* Zombie = Cast<AZombie>(InPawn);
	if (Zombie && Zombie->BehaviorTree)
	{
		RunBehaviorTree(Zombie->BehaviorTree);
	}

	SetGenericTeamId(3);
	Perception->OnTargetPerceptionUpdated.AddDynamic(this, &AZombieAIController::ProcessPerceptionUpdate);
	Perception->OnTargetPerceptionForgotten.AddDynamic(this, &AZombieAIController::ProcessPerceptionForgotten);
}

void AZombieAIController::ProcessPerceptionUpdate(AActor* Actor, FAIStimulus Stimulus)
{
	if (Stimulus.Type == UAISense::GetSenseID<UAISense_Sight>())
	{
		AZombie* Zombie = Cast<AZombie>(GetPawn());
		AUEAISampleCharacter* Player = Cast<AUEAISampleCharacter>(Actor);
		if(!Zombie || !Player)
		{
			return;
		}
		if (Zombie->CurrentState == EZombieState::Death)
		{
			return;
		}

		if (Stimulus.WasSuccessfullySensed())
		{
			Zombie->SetCurrentState(EZombieState::Chase);		
			Blackboard->SetValueAsObject(TEXT("Player"), Player);
		}
		else
		{
			Zombie->SetCurrentState(EZombieState::Normal);
		}
	}
	else if (Stimulus.Type == UAISense::GetSenseID<UAISense_Hearing>())
	{
		if (Stimulus.WasSuccessfullySensed())
		{
			UE_LOG(LogTemp, Warning, TEXT("Heard something!"));
		}
	}
}

void AZombieAIController::ProcessPerceptionForgotten(AActor* Actor)
{

}
