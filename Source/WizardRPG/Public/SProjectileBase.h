// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SProjectileBase.generated.h"
class USphereComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;
UCLASS()
class WIZARDRPG_API ASProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	ASProjectileBase();

protected:
	UPROPERTY(EditAnywhere,Category="Component")
		USphereComponent* SphereComp;
	UPROPERTY(EditAnywhere,Category="Mesh")
		UStaticMeshComponent* ProjectileMesh;
	UPROPERTY(EditAnywhere,Category="Component")
		UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(EditDefaultsOnly,Category="Attack")
		float Damage;

	UFUNCTION()
		virtual void OnActorOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	virtual void PostInitializeComponents() override;

};
