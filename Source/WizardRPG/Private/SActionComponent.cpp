// Fill out your copyright notice in the Description page of Project Settings.


#include "SActionComponent.h"
#include "SAction.h"

// Sets default values for this component's properties
USActionComponent::USActionComponent()
{
	
}


void USActionComponent::AddAction(TSubclassOf<USAction> ActionClass)
{
	if (!ensure(ActionClass))
	{
		return;
	}
	USAction* NewAction = NewObject<USAction>(this, ActionClass);
	if (NewAction)
	{
		Actions.Add(NewAction);
	}

}

bool USActionComponent::StartActionByName(AActor* Instigator, FName ActionName)
{
	for (USAction* Action : Actions)
	{
		if (Action && Action->ActionName==ActionName)
		{
			Action->StartAction(Instigator);
			return true;
		}
	}
	return false;

}

bool USActionComponent::StopActionByName(AActor* Instigator, FName ActionName)
{
	for (USAction* Action : Actions)
	{
		if (Action && Action->ActionName == ActionName)
		{
			Action->StopAction(Instigator);
			return true;
		}
	}
	return false;
}

// Called when the game starts
void USActionComponent::BeginPlay()
{
	Super::BeginPlay();

	for (TSubclassOf<USAction> ActionClass : DefaultActions)
	{
		AddAction(ActionClass);
	}
	
}


