// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGameplayInterface.h"
#include "SItemChest.generated.h"
class UStaticMeshComponent;
UCLASS()
class WIZARDRPG_API ASItemChest : public AActor,public ISGameplayInterface
{
	GENERATED_BODY()
	
public:	
	ASItemChest();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		UStaticMeshComponent* BaseMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
		UStaticMeshComponent* LidMesh;
	
	void Interact_Implementation(APawn* InstigatorPawm);
	virtual void BeginPlay() override;

public:		
	virtual void Tick(float DeltaTime) override;

};
