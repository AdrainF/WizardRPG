// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SProjectileBase.h"
#include "SBlackHole.generated.h"

/**
 *
 */
class URadialForceComponent;
UCLASS()
class WIZARDRPG_API ASBlackHole : public ASProjectileBase
{
	GENERATED_BODY()

public:
	ASBlackHole();

protected:
	UPROPERTY(EditDefaultsOnly)
		URadialForceComponent* ForceComp;

	virtual void OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};
