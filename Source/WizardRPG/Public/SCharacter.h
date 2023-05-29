// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class USInteractionComponent;
class USActionComponent;
UCLASS()
class WIZARDRPG_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:	
	ASCharacter();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Camera")
		UCameraComponent* CameraComp;
	UPROPERTY(VisibleAnywhere, Category = "Camera")
		USpringArmComponent* SpringArmComp;
	UPROPERTY(EditAnywhere,Category="Component")
		USInteractionComponent* InteractComp;
	UPROPERTY(EditDefaultsOnly,Category="Component")
		USActionComponent* ActionComp;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void PrimaryInteract();
	void PrimaryAttack();
	void BlackHole();
	void Teleport();
	
	virtual void BeginPlay() override;

public:	
	virtual FVector GetPawnViewLocation() const override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
