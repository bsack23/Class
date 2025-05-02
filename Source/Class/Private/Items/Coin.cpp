// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/Coin.h"
#include "Characters/MyCharacter.h"

void ACoin::OnOverlapBegin(class UPrimitiveComponent *OverlappedComp,
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
    // doo stuffs
    MyCharacter->IncCoins();
  }
  // mmm? well, it works
  Destroy();
}