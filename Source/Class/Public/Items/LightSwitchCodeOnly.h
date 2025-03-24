// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
// add this
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightSwitchCodeOnly.generated.h"

UCLASS()
class CLASS_API ALightSwitchCodeOnly : public AActor {
  GENERATED_BODY()

public:
  // add this:
  /** point light component */
  UPROPERTY(VisibleAnywhere, Category = "Switch Components")
  class UPointLightComponent *PointLight1;

  /** sphere component */
  UPROPERTY(VisibleAnywhere, Category = "Switch Components")
  class USphereComponent *Sphere1;

  // Sets default values for this actor's properties
  ALightSwitchCodeOnly();

  UFUNCTION()
  void OnOverlapBegin(class UPrimitiveComponent *OverlappedComp,
                      class AActor *OtherActor,
                      class UPrimitiveComponent *OtherComp,
                      int32 OtherBodyIndex, bool bFromSweep,
                      const FHitResult &SweepResult);

  /** called when something leaves the sphere component */
  UFUNCTION()
  void OnOverlapEnd(class UPrimitiveComponent *OverlappedComp,
                    class AActor *OtherActor,
                    class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex);

  /** the desired intensity for the light */
  UPROPERTY(VisibleAnywhere, Category = "Switch Variables")
  float DesiredIntensity;

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;
};
