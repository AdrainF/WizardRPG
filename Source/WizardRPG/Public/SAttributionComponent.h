#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SAttributionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHealthChange, AActor*, InstigatorActor, USAttributionComponent*, OwningComp, float, NewHealth, float, Delta);

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
	UPROPERTY(BlueprintAssignable)
		FOnHealthChange OnHealthChange;

	UFUNCTION(BlueprintCallable)
		const float GetHealth();
	UFUNCTION(BlueprintCallable)
		const float GetHealthMax();
	UFUNCTION(BlueprintCallable)
		bool ApplyHealthChange(const float Delta);
		
};
