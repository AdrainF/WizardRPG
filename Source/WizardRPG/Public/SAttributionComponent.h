#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SAttributionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WIZARDRPG_API USAttributionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	USAttributionComponent();

protected:
	UPROPERTY(EditDefaultsOnly,Category="Attribute")
		float Health;
	UPROPERTY(EditDefaultsOnly, Category = "Attribute")
		float HealthMax;

	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable)
		const float GetHealth();
	UFUNCTION(BlueprintCallable)
		const float GetHealthMax();
	UFUNCTION(BlueprintCallable)
		bool ApplyHealthChange(const float Delta);
		
};
