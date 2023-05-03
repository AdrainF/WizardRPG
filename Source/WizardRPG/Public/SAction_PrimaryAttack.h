// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SAction.h"
#include "SAction_PrimaryAttack.generated.h"
class AActor;
/**
 * 
 */
UCLASS(Blueprintable)
class WIZARDRPG_API USAction_PrimaryAttack : public USAction
{
	GENERATED_BODY()
	
public:
	USAction_PrimaryAttack();

	
		virtual void StartAction_Implementation(AActor* Instigator) override;

protected:
	UPROPERTY(EditDefaultsOnly,Category="Projectile")
	TSubclassOf<AActor> ProjectileClass;
	
	void SpawnActor(TSubclassOf<AActor> const ClassToSpawm,AActor* InstigatorActor);

};
