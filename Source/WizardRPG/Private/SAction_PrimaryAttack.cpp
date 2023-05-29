// Fill out your copyright notice in the Description page of Project Settings.


#include "SAction_PrimaryAttack.h"
#include <GameFramework/Actor.h>
#include "SCharacter.h"
#include <TimerManager.h>
USAction_PrimaryAttack::USAction_PrimaryAttack()
{
	HandSocketName = "Muzzle_01";
	AttackAnimDelay = 0.2f;

	SweepRadius = 20.0f;
	SweepDistance = 5000.0f;
}

void USAction_PrimaryAttack::StartAction_Implementation(AActor* Instigator)
{
	Super::StartAction_Implementation(Instigator);

	ACharacter* Character = Cast<ACharacter>(Instigator);
	if (Character)
	{
		Character->PlayAnimMontage(AttackAnim);

		FTimerHandle TimeHandle_AttackDelay;
		FTimerDelegate Delegate;
		Delegate.BindUFunction(this, "AttackDelay_Elapsed", Character);

		GetWorld()->GetTimerManager().SetTimer(TimeHandle_AttackDelay, Delegate, AttackAnimDelay, false);
	}

	
}

void USAction_PrimaryAttack::AttackDelay_Elapsed(ACharacter* InstigatorCharacter)
{
	if (ensure(ProjectileClass))
	{
		FVector HandLocation = InstigatorCharacter->GetMesh()->GetSocketLocation(HandSocketName);

		// We trace against to find whats under the player crosshair.
		// We use the hit location to adjust the projectile launch direction so it will hit what is under the crosshair rather than shoot straight forward from the player hands.

		FActorSpawnParameters SpawnParam;
		SpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		SpawnParam.Instigator = InstigatorCharacter;

		FCollisionShape CollisionShape;
		CollisionShape.SetSphere(SweepRadius);

		FVector SpawnRotation = InstigatorCharacter->GetControlRotation().Vector();
		//Add sweep radius to avoid projectile targeting objects directly against camera.
		FVector TraceStart = InstigatorCharacter->GetPawnViewLocation()+ (SpawnRotation* SweepRadius);
		// endpoint far into the look-at distance
		FVector TraceEnd = TraceStart + (SpawnRotation * SweepDistance);

		
		FCollisionObjectQueryParams  ObjParams;
		ObjParams.AddObjectTypesToQuery(ECC_WorldDynamic);
		ObjParams.AddObjectTypesToQuery(ECC_WorldStatic);
		ObjParams.AddObjectTypesToQuery(ECC_Pawn);
		
		//Ignore Player
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(InstigatorCharacter);

		FHitResult Hit;		
		// return true if we got to a blocking hit
		if (GetWorld()->SweepSingleByObjectType(Hit,TraceStart,TraceEnd,FQuat::Identity,ObjParams,CollisionShape,Params))
		{
			// Overwrite  trace end with hit impact point.
			TraceEnd = Hit.ImpactPoint;
		}

		// find new direction/rotation from Hand pointing to impact point in world.
		FRotator ProjectileRotation = FRotationMatrix::MakeFromX(TraceEnd - HandLocation).Rotator();

		FTransform SpawnTM = FTransform(ProjectileRotation, HandLocation);
		GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParam);

	}

}


