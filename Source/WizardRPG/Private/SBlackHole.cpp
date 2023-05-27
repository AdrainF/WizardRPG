// Fill out your copyright notice in the Description page of Project Settings.


#include "SBlackHole.h"
#include <GameFramework/ProjectileMovementComponent.h>
#include <Components/SphereComponent.h>
#include <PhysicsEngine/RadialForceComponent.h>

ASBlackHole::ASBlackHole()
{
	ProjectileMovement->InitialSpeed = 300.0f;
	SphereComp->SetSphereRadius(84.0f);

	ForceComp = CreateDefaultSubobject<URadialForceComponent>("ForceComp");
	ForceComp->SetupAttachment(SphereComp);
	ForceComp->ForceStrength = -10000.0f;
	

}

void ASBlackHole::OnActorOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor!= GetInstigator())
	{
		OtherActor->Destroy();
	}
}

