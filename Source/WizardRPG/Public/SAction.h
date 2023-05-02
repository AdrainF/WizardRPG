// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SAction.generated.h"

/**
 * 
 */
UCLASS()
class WIZARDRPG_API USAction : public UObject
{
	GENERATED_BODY()

public:
	USAction();

	UPROPERTY(EditDefaultsOnly,Category="Action")
		FName ActionName;
	UFUNCTION(BlueprintNativeEvent,Category="Action")
		void StartAction(AActor* Instigator);
	UFUNCTION(BlueprintNativeEvent, Category = "Action")
		void StopAction(AActor* Instigator);


	
};
