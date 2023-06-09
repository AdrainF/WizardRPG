// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SActionComponent.generated.h"

class USAction;
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WIZARDRPG_API USActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	USActionComponent();

	UFUNCTION(BlueprintCallable, Category = "Actions")
		void AddAction(TSubclassOf<USAction> ActionClass);
	UFUNCTION(BlueprintCallable, Category = "Actions")
		bool StartActionByName(AActor* Instigator, FName ActionName);
	UFUNCTION(BlueprintCallable, Category = "Actions")
		bool StopActionByName(AActor* Instigator, FName ActionName);

protected:
	UPROPERTY()
	TArray<USAction*> Actions;
	UPROPERTY(EditDefaultsOnly,Category="Actions")
	TArray<TSubclassOf<USAction>> DefaultActions;

	virtual void BeginPlay() override;

};
