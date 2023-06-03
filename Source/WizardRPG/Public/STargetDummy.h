// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STargetDummy.generated.h"

class USAttributionComponent;
UCLASS()
class WIZARDRPG_API ASTargetDummy : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ASTargetDummy();

protected:
	UPROPERTY(EditAnywhere,Category="Component")
		UStaticMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere,Category="Component")
		USAttributionComponent* AttriComp;

	UFUNCTION()
		void OnHealthChange(AActor* InstigatorActor,USAttributionComponent* OwningComp,float Health,float Delat);

};
