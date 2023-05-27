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
	
	// Sphere radius of the sweep to find desired target under crosshair
	UPROPERTY(EditAnywhere,Category="Targeting")
	float SweepRadius;

	//Distance when sweep finds no collison
	UPROPERTY(EditAnywhere,Category="Targeting")
	float SweepDistance;

	UPROPERTY(EditAnywhere,Category="Targeting")
	float TraceRadius;

	UPROPERTY(EditDefaultsOnly,Category="Attack")
	TSubclassOf<AActor> ProjectileClass;

	UPROPERTY(VisibleAnywhere, Category = "Effects")
	FName HandSocketName;

	UPROPERTY(EditDefaultsOnly, Category = "Attack")
	float AttackAnimDelay;

	UPROPERTY(EditAnywhere, Category = "Attack")
	TObjectPtr<UAnimMontage> AttackAnim;

	UFUNCTION()
	void AttackDelay_Elapsed(ACharacter* InstigatorCharacter);
	

};
