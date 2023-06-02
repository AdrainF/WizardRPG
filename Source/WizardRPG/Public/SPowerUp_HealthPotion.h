// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SPowerUpActor.h"
#include "SPowerUp_HealthPotion.generated.h"

/**
 * 
 */
UCLASS()
class WIZARDRPG_API ASPowerUp_HealthPotion : public ASPowerUpActor
{
	GENERATED_BODY()
	
public:
	ASPowerUp_HealthPotion();

	virtual void Interact_Implementation(APawn* InstigatorPawn);

};
