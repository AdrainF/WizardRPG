#include "SProjectileBase.h"
#include <Components/SphereComponent.h>
#include <GameFramework/ProjectileMovementComponent.h>
#include "SAttributionComponent.h"
#include <Particles/ParticleSystemComponent.h>
#include <Kismet/GameplayStatics.h>

ASProjectileBase::ASProjectileBase()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	RootComponent = SphereComp;

	ProjectileMesh = CreateDefaultSubobject<UParticleSystemComponent>("ProjectileMesh");
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
			AttriComp->ApplyHealthChange(-Damage);
			Explode();
		}
	}
}

void ASProjectileBase::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor!=GetInstigator())
	{
		Explode();
	}
}

void ASProjectileBase::Explode_Implementation()
{
	if (ensure(IsValid(this)))
	{	
		UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVFX, GetActorLocation(), GetActorRotation());
		Destroy();
	}
}

void ASProjectileBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	SphereComp->IgnoreActorWhenMoving(GetInstigator(), true);
	SphereComp->OnComponentHit.AddDynamic(this, &ASProjectileBase::OnActorHit);
}


