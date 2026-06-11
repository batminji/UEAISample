// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_CheckDistance.generated.h"

UENUM(BlueprintType)
enum class ECondition : uint8
{
	LessThen		= 0 UMETA(DisplayName = "<"),
	GreaterThen		= 1 UMETA(DisplayName = ">")
};

UCLASS()
class UEAISAMPLE_API UBTTask_CheckDistance : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Condition")
	ECondition TargetCondition;
};
