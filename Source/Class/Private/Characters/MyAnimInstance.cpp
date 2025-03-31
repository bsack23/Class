// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/MyAnimInstance.h"

#include "Characters/MyCharacter.h"
// for GetCharacterMovement
#include "GameFramework/CharacterMovementComponent.h"
// for Kismet - need for the VSizeXY method to get the XY magnitude of
// our Velocity vector
#include "Kismet/KismetMathLibrary.h"

// initialize animation
void UMyAnimInstance::NativeInitializeAnimation() {
  Super::NativeInitializeAnimation();
  // variables declared in .h
  // cast from Pawn returned by TryGetPawnOwner to Character
  MyCharacter = Cast<AMyCharacter>(TryGetPawnOwner());
  if (MyCharacter) {
    // get the Character Movement property
    // and set our CharacterMovement
    MyCharacterMovement = MyCharacter->GetCharacterMovement();
  }
}

void UMyAnimInstance::NativeUpdateAnimation(float DeltaTime) {
  // loop continually updating animations
  Super::NativeUpdateAnimation(DeltaTime);
  if (MyCharacterMovement) {
    // set our variables from CharacterMovement
    GroundSpeed = UKismetMathLibrary::VSizeXY(MyCharacterMovement->Velocity);
    IsFalling = MyCharacterMovement->IsFalling();
  }
}
