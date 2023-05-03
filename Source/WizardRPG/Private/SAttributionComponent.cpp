#include "SAttributionComponent.h"

USAttributionComponent::USAttributionComponent()
{

	PrimaryComponentTick.bCanEverTick = true;
	HealthMax = 100;
	Health = HealthMax;

}

void USAttributionComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

const float USAttributionComponent::GetHealth()
{
	return Health;
}

const float USAttributionComponent::GetHealthMax()
{
	return HealthMax;
}

bool USAttributionComponent::ApplyHealthChange(const float Delta)
{
	
	float NewHealth = FMath::Clamp(Health + Delta, 0.0f, HealthMax);
	Health = NewHealth;
	OnHealthChange.Broadcast(nullptr, this, Health, Delta);
	return true;
}
