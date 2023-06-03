// Fill out your copyright notice in the Description page of Project Settings.


#include "STargetDummy.h"
#include "SAttributionComponent.h"

// Sets default values
ASTargetDummy::ASTargetDummy()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComp;

	AttriComp = CreateDefaultSubobject<USAttributionComponent>("AttriComp");
	AttriComp->OnHealthChange.AddDynamic(this, &ASTargetDummy::OnHealthChange);

}

void ASTargetDummy::OnHealthChange(AActor* InstigatorActor, USAttributionComponent* OwningComp, float Health, float Delat)
{
	MeshComp->SetScalarParameterValueOnMaterials("TimeToHit", GetWorld()->TimeSeconds);

}
