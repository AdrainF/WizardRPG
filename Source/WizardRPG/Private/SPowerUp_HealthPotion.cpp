// Fill out your copyright notice in the Description page of Project Settings.


#include "SPowerUp_HealthPotion.h"
#include "SCharacter.h"
#include "SAttributionComponent.h"

ASPowerUp_HealthPotion::ASPowerUp_HealthPotion()
{

}

void ASPowerUp_HealthPotion::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}


	USAttributionComponent * AttriComp = InstigatorPawn->FindComponentByClass<USAttributionComponent>();
	if (AttriComp && AttriComp->GetHealth()<AttriComp->GetHealthMax())
	{
		AttriComp->ApplyHealthChange(AttriComp->GetHealthMax());
		HideAndCooldownPowerUp();
	}
}
