// Fill out your copyright notice in the Description page of Project Settings.


#include "SPowerUpActor.h"
#include <Components/SphereComponent.h>
#include <Components/StaticMeshComponent.h>

// Sets default values
ASPowerUpActor::ASPowerUpActor()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	RootComponent = SphereComp;
	SphereComp->SetCollisionProfileName("PowerUp");

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	MeshComp->SetupAttachment(SphereComp);

	RespownTime = 10.0f;
	bIsActive = true;
}

void ASPowerUpActor::OnRep_IsActive()
{
	SetActorEnableCollision(bIsActive);
	RootComponent->SetVisibility(bIsActive, true);
}

void ASPowerUpActor::ShowPowerUp()
{
	SetPowerUpState(true);
}

void ASPowerUpActor::HideAndCooldownPowerUp()
{
	SetPowerUpState(false);

	GetWorld()->GetTimerManager().SetTimer(TimeHandle_RespownTimer,this, &ASPowerUpActor::ShowPowerUp, RespownTime);
}

void ASPowerUpActor::SetPowerUpState(bool bNewIsActive)
{
	bIsActive = bNewIsActive;

	OnRep_IsActive();
}

// Called when the game starts or when spawned
void ASPowerUpActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASPowerUpActor::Interact_Implementation(APawn* InstigatorPawn)
{

}

// Called every frame
void ASPowerUpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

