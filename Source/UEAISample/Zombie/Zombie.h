// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Zombie.generated.h"

UENUM(BlueprintType)
enum class EZombieState : uint8
{
	Normal			= 0 UMETA(DisplayName = "Normal"),
	Chase			= 1 UMETA(DisplayName = "Chase"),
	Attacking		= 2 UMETA(DisplayName = "Attacking"),
	Death			= 3 UMETA(DisplayName = "Death")
};

UCLASS()
class UEAISAMPLE_API AZombie : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZombie();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
