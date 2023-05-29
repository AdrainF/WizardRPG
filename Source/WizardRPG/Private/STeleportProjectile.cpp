// Fill out your copyright notice in the Description page of Project Settings.


#include "STeleportProjectile.h"
#include <GameFramework/ProjectileMovementComponent.h>
#include <Components/SphereComponent.h>
ASTeleportProjectile::ASTeleportProjectile()
{
	DestroyDelay = 0.5f;
	ProjectileMovement->InitialSpeed = 6000.f;

}

void ASTeleportProjectile::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	FTimerHandle TimeHandle_DestoryDelay;

	SphereComp->IgnoreActorWhenMoving(GetInstigator(),true);

	GetWorld()->GetTimerManager().SetTimer(TimeHandle_DestoryDelay, this, &ASTeleportProjectile::Explode, DestroyDelay, false);
}

void ASTeleportProjectile::Explode_Implementation()
{
	AActor* ActorToTeleport = GetInstigator();
	if (ActorToTeleport)
	{
		ActorToTeleport->TeleportTo(GetActorLocation(), ActorToTeleport->GetActorRotation(), false, false);

	}
	Destroy();
}
