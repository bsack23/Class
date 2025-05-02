// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
// clang-format off
#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Coin.generated.h"

/**
 *
 */
UCLASS()
class CLASS_API ACoin : public AItem {
  GENERATED_BODY()

  protected:
  // redeclare functions as overrides from the parent versions in Item.h
  // can't use UFUNCTION here because they're already declared in Item.h
  // UFUNCTION()
  virtual void OnOverlapBegin(class UPrimitiveComponent *OverlappedComp,
                              class AActor *OtherActor,
                              class UPrimitiveComponent *OtherComp,
                              int32 OtherBodyIndex, bool bFromSweep,
                              const FHitResult &SweepResult) override;
	
//public:


};
