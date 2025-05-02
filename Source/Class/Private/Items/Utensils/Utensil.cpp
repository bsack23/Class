// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Utensils/Utensil.h"
// need to include header for MyCharacter because we're attaching
// this to a socket on its skeletal mesh
#include "Characters/MyCharacter.h"

void AUtensil::OnOverlapBegin(class UPrimitiveComponent *OverlappedComp,
                              class AActor *OtherActor,
                              class UPrimitiveComponent *OtherComp,
                              int32 OtherBodyIndex, bool bFromSweep,
                              const FHitResult &SweepResult) {
  // use Super to call version of this func from parent class (Item)
  Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex,
                        bFromSweep, SweepResult);
  // cast from MyCharacter class so we can attach this to its socket
  AMyCharacter *MyCharacter = Cast<AMyCharacter>(OtherActor);
  // check for valid Character
  if (MyCharacter) {
    // assign transform rules for attachment
    FAttachmentTransformRules TransformRules(EAttachmentRule::SnapToTarget,
                                             TRUE);
    // do the attachment
    ItemMesh->AttachToComponent(MyCharacter->GetMesh(), TransformRules,
                                FName("RightHandSocket"));
    RotationRate = 0;
    // experiment
    EquippedState = true;
  }
}

void AUtensil::OnOverlapEnd(class UPrimitiveComponent *OverlappedComp,
                            class AActor *OtherActor,
                            class UPrimitiveComponent *OtherComp,
                            int32 OtherBodyIndex) {
  Super::OnOverlapEnd(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex);
}