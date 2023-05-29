// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SProjectileBase.h"
#include "STeleportProjectile.generated.h"

/**
 * 
 */
UCLASS()
class WIZARDRPG_API ASTeleportProjectile : public ASProjectileBase
{
	GENERATED_BODY()

public:
	ASTeleportProjectile();
	
protected:	
	UPROPERTY(EditDefaultsOnly,Category="Action")
		float DestroyDelay;

	virtual void PostInitializeComponents() override;

	virtual void Explode_Implementation() override;

};
