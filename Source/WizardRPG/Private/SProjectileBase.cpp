#include "SProjectileBase.h"
#include <Components/SphereComponent.h>
#include <Components/StaticMeshComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include "SAttributionComponent.h"

ASProjectileBase::ASProjectileBase()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	RootComponent = SphereComp;
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("ProjectileMesh");
	ProjectileMesh->SetupAttachment(SphereComp);
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
	ProjectileMovement->InitialSpeed = 1000.0f;
	ProjectileMovement->ProjectileGravityScale = 0.0f;
	SphereComp->OnComponentBeginOverlap.AddDynamic(this,&ASProjectileBase::OnActorOverlap );

}


void ASProjectileBase::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor!=GetInstigator())
	{
		USAttributionComponent* AttriComp = Cast<USAttributionComponent>(OtherActor->GetComponentByClass(USAttributionComponent::StaticClass()));
		
		if (AttriComp)
		{
			AttriComp->ApplyHealthChange(Damage);
		}
	}
}

void ASProjectileBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();

}


