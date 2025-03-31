// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Animation/AnimInstance.h"
#include "CoreMinimal.h"
#include "MyAnimInstance.generated.h"

/**
 *
 */
UCLASS()
class CLASS_API UMyAnimInstance : public UAnimInstance {
  GENERATED_BODY()
  // ADD THIS!
public:
  // these are the analogs to the core BP nodes
  virtual void NativeInitializeAnimation() override;
  virtual void NativeUpdateAnimation(float DeltaTime) override;
  // make a pointer to MyCharacter - forward declared
  // BlueprintReadOnly so we can use it in the event graph
  UPROPERTY(BlueprintReadOnly)
  class AMyCharacter *MyCharacter;
  // make a movement component - also forward declared
  UPROPERTY(BlueprintReadOnly, Category = Movement)
  class UCharacterMovementComponent *MyCharacterMovement;
  // plain old variables
  UPROPERTY(BlueprintReadOnly, Category = Movement)
  float GroundSpeed;

  UPROPERTY(BlueprintReadOnly, Category = Movement)
  bool IsFalling;
};
