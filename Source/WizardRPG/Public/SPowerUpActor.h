// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGameplayInterface.h"
#include "SPowerUpActor.generated.h"

class USphereComponent;
class UStaticMeshComponent;
UCLASS()
class WIZARDRPG_API ASPowerUpActor : public AActor, public ISGameplayInterface
{
	GENERATED_BODY()
	
public:	
	ASPowerUpActor();

protected:
	UPROPERTY(EditAnywhere,Category="PowerUp")
		float RespownTime;

	UPROPERTY(EditAnywhere,Category="Component")
		USphereComponent* SphereComp;

	UPROPERTY(EditAnywhere,Category="Component")
		UStaticMeshComponent* MeshComp;

	FTimerHandle TimeHandle_RespownTimer;

	bool bIsActive;

	UFUNCTION()
		void OnRep_IsActive();

	UFUNCTION()
		void ShowPowerUp();

	void HideAndCooldownPowerUp();

	void SetPowerUpState(bool bNewIsActive);
	
	virtual void BeginPlay() override;

public:	
	virtual void Interact_Implementation(APawn* InstigatorPawn) override;

	virtual void Tick(float DeltaTime) override;

};
