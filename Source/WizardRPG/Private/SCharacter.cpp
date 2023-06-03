// Fill out your copyright notice in the Description page of Project Settings.


#include "SCharacter.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include <GameFramework/Character.h>
#include <GameFramework\CharacterMovementComponent.h>
#include "SInteractionComponent.h"
#include "SActionComponent.h"
#include "SAttributionComponent.h"

// Sets default values
ASCharacter::ASCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);
	SpringArmComp->TargetArmLength = 600.0f;
	SpringArmComp->bUsePawnControlRotation = true;

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;

	InteractComp = CreateDefaultSubobject<USInteractionComponent>("InteractComp");

	ActionComp = CreateDefaultSubobject<USActionComponent>("ActionComp");

	AttriComp = CreateDefaultSubobject<USAttributionComponent>("AttriComp");
	AttriComp->OnHealthChange.AddDynamic(this, &ASCharacter::OnHealthChange);

}

void ASCharacter::MoveForward(float Value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	AddMovementInput(ControlRot.Vector(), Value);
}

void ASCharacter::MoveRight(float Value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;
	FVector RightRot = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);

	AddMovementInput(RightRot, Value);

}

void ASCharacter::PrimaryInteract()
{
	InteractComp->PrimaryInteract();
	
}

void ASCharacter::PrimaryAttack()
{
	ActionComp->StartActionByName(this,"PrimaryAttack");
}

void ASCharacter::BlackHole()
{
	ActionComp->StartActionByName(this, "BlackHole");
}

void ASCharacter::Teleport()
{
	ActionComp->StartActionByName(this, "Teleport");
}

void ASCharacter::OnHealthChange(AActor* InstigatorActor, USAttributionComponent* OwningComp, float NewHealth, float Delta)
{
	if (Delta<0.0f)
	{
		GetMesh()->SetScalarParameterValueOnMaterials("TimeToHit", GetWorld()->TimeSeconds);
	}

}

FVector ASCharacter::GetPawnViewLocation() const
{
	return CameraComp->GetComponentLocation();
}

void ASCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void ASCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ASCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ASCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Turn", this, &ASCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ASCharacter::Jump);
	PlayerInputComponent->BindAction("PrimaryInteract", IE_Pressed, this, &ASCharacter::PrimaryInteract);
	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &ASCharacter::PrimaryAttack);
	PlayerInputComponent->BindAction("BlackHole", IE_Pressed, this, &ASCharacter::BlackHole);
	PlayerInputComponent->BindAction("Teleport", IE_Pressed, this, &ASCharacter::Teleport);
}

