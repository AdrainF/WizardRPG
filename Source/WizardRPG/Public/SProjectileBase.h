// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SProjectileBase.generated.h"
class USphereComponent;
class UParticleSystemComponent;
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
		UParticleSystemComponent* ProjectileMesh;
	UPROPERTY(EditAnywhere,Category="Component")
		UProjectileMovementComponent* ProjectileMovement;
	UPROPERTY(EditDefaultsOnly,Category="Attack")
		float Damage;

	UFUNCTION()
		virtual void OnActorOverlap( UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		virtual void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	UFUNCTION(BlueprintNativeEvent,BlueprintCallable)
		void Explode();

public:	
	virtual void PostInitializeComponents() override;

};
