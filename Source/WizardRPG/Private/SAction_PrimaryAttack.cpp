// Fill out your copyright notice in the Description page of Project Settings.


#include "SAction_PrimaryAttack.h"
#include <GameFramework/Character.h>
#include <GameFramework/Actor.h>
USAction_PrimaryAttack::USAction_PrimaryAttack()
{

}

void USAction_PrimaryAttack::StartAction_Implementation(AActor* Instigator)
{
	SpawnActor(ProjectileClass,Instigator);
}

void USAction_PrimaryAttack::SpawnActor(TSubclassOf<AActor> const ClassToSpawm, AActor* InstigatorActor)
{
	if (ensure(ClassToSpawm))
	{
		FVector SpawnLocation;
		FRotator SpawnRotation;
		FActorSpawnParameters SpawnParam;

		ACharacter* MyCharacter = Cast<ACharacter>(InstigatorActor);
		SpawnLocation = MyCharacter->GetMesh()->GetSocketLocation("Muzzle_01");
		SpawnRotation = MyCharacter->GetActorRotation();
		SpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParam.Instigator = MyCharacter;

		GetWorld()->SpawnActor<AActor>(ClassToSpawm, SpawnLocation, SpawnRotation, SpawnParam);

	}

}


