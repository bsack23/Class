// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class CLASS_API AItem : public AActor {
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  AItem();

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

  // NEW!!!

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
  float Amplitude = 0.25f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
  float TimeConstant = 5.f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float RotationRate = 40.f;

  // UFUNCTION(BlueprintPure) // returns a value on blueprint
  // float TransformedSin();

  // UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
  // UStaticMeshComponent *ItemMesh;
  // end NEW

  // NEW!!!
private:
  UPROPERTY(VisibleAnywhere, BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float RunningTime;

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly,
            meta = (AllowPrivateAccess = "true"))
  float PerlinValue;

  // end NEW

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;
};
