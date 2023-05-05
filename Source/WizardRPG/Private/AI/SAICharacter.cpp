// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SAICharacter.h"
#include "SAttributionComponent.h"

// Sets default values
ASAICharacter::ASAICharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	AttriComp = CreateDefaultSubobject<USAttributionComponent>("AttriComp");

}

void ASAICharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
 
void ASAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

