// Fill out your copyright notice in the Description page of Project Settings.


#include "SAction_PrimaryAttack.h"
#include <GameFramework/Actor.h>
#include "SCharacter.h"
USAction_PrimaryAttack::USAction_PrimaryAttack()
{
	TraceRadius = 20.0f;
}

void USAction_PrimaryAttack::StartAction_Implementation(AActor* Instigator)
{
	SpawnActor(ProjectileClass,Instigator);
}

void USAction_PrimaryAttack::SpawnActor(TSubclassOf<AActor> const ClassToSpawm, AActor* InstigatorActor)
{
	if (ensure(ClassToSpawm))
	{
		FVector HandLocation;
		FRotator SpawnRotation;
		FVector TraceStart;
		FVector TraceEnd;
		FActorSpawnParameters SpawnParam;
		ASCharacter* MyCharacter = Cast<ASCharacter>(InstigatorActor);
		HandLocation = MyCharacter->GetMesh()->GetSocketLocation("Muzzle_01");
		SpawnRotation = MyCharacter->GetActorRotation();
		SpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParam.Instigator = MyCharacter;
		TraceStart = MyCharacter->GetPawnViewLocation();
		TraceEnd = MyCharacter->GetPawnViewLocation() + (MyCharacter->GetControlRotation().Vector() * 5000);
		FHitResult Hit;
		FCollisionObjectQueryParams  ObjParams;
		ObjParams.AddObjectTypesToQuery(ECC_WorldDynamic);
		ObjParams.AddObjectTypesToQuery(ECC_WorldStatic);
		ObjParams.AddObjectTypesToQuery(ECC_Pawn);
		FCollisionShape CollisionShape;
		CollisionShape.SetSphere(TraceRadius);
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(InstigatorActor);

		if (GetWorld()->SweepSingleByObjectType(Hit,TraceStart,TraceEnd,FQuat::Identity,ObjParams,CollisionShape,Params))
		{
			SpawnRotation = FRotationMatrix::MakeFromX(Hit.ImpactPoint - HandLocation).Rotator();
		}
		else
		{
			SpawnRotation = FRotationMatrix::MakeFromX(TraceEnd - HandLocation).Rotator();
		}


		GetWorld()->SpawnActor<AActor>(ClassToSpawm, HandLocation, SpawnRotation, SpawnParam);

	}

}


