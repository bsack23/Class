// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
// clang-format off
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
// this is only here temporarily until we forward declare!
//#include "Components/CapsuleComponent.h"
// this include must be last!!
#include "Bird.generated.h"

// forward declarations here
class UCapsuleComponent;
class USkeletalMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class CLASS_API ABird : public APawn {
  GENERATED_BODY()

public:
  // Sets default values for this pawn's properties
  ABird();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

  // Called to bind functionality to input
  virtual void SetupPlayerInputComponent(
      class UInputComponent *PlayerInputComponent) override;
private:
  UPROPERTY(VisibleAnywhere)
  UCapsuleComponent *Capsule; 

  UPROPERTY(VisibleAnywhere)
  USkeletalMeshComponent *BirdMesh;

  UPROPERTY(VisibleAnywhere)
  USpringArmComponent* SpringArm;

  UPROPERTY(VisibleAnywhere)
  UCameraComponent* ViewCamera;

};
