// Fill out your copyright notice in the Description page of Project Settings.

#include "Items/LightSwitchCodeOnly.h"

// Sets default values
ALightSwitchCodeOnly::ALightSwitchCodeOnly() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it. PrimaryActorTick.bCanEverTick =
  // true; ADD THIS:
  DesiredIntensity = 3000.0f;
  // FColor NewLightColor = FColor(255, 0, 255, 255);
  PointLight1 =
      CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight1"));
  PointLight1->Intensity = DesiredIntensity;
  PointLight1->SetVisibility(false);
  // PointLight1->SetLightFColor(NewLightColor);
  RootComponent = PointLight1;

  Sphere1 = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere1"));
  Sphere1->InitSphereRadius(150.0f);
  Sphere1->SetupAttachment(RootComponent);

  Sphere1->OnComponentBeginOverlap.AddDynamic(
      this, &ALightSwitchCodeOnly::OnOverlapBegin); // set up a notification for
                                                    // when this component
                                                    // overlaps something
  Sphere1->OnComponentEndOverlap.AddDynamic(
      this,
      &ALightSwitchCodeOnly::OnOverlapEnd); // set up a notification for when
                                            // this component overlaps something
}

// Called when the game starts or when spawned
void ALightSwitchCodeOnly::BeginPlay() { Super::BeginPlay(); }

// Called every frame
void ALightSwitchCodeOnly::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

void ALightSwitchCodeOnly::OnOverlapBegin(
    class UPrimitiveComponent *OverlappedComp, class AActor *OtherActor,
    class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep,
    const FHitResult &SweepResult) {
  if (OtherActor && (OtherActor != this) && OtherComp) {
    // ToggleLight();
    PointLight1->SetVisibility(true);
  }
}

void ALightSwitchCodeOnly::OnOverlapEnd(
    class UPrimitiveComponent *OverlappedComp, class AActor *OtherActor,
    class UPrimitiveComponent *OtherComp, int32 OtherBodyIndex) {
  if (OtherActor && (OtherActor != this) && OtherComp) {
    // ToggleLight();
    PointLight1->SetVisibility(false);
  }
}