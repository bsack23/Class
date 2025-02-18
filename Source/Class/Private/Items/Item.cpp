// Fill out your copyright notice in the Description page of Project Settings.
// Perlin1D
// https://dev.epicgames.com/documentation/en-us/unreal-engine/API/Runtime/Core/Math/FMath/PerlinNoise1D?application_version=5.5

#include "Items/Item.h"
// NEW!!
#include "Components/StaticMeshComponent.h"
#include "Math/UnrealMathUtility.h" // for Perlin & sin
// end NEW

// Sets default values
AItem::AItem() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
  // NEW!!!
  // ItemMesh =
  //     CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMeshComponent"));
  // RootComponent = ItemMesh;
  // end NEW
}

// Called when the game starts or when spawned
void AItem::BeginPlay() { Super::BeginPlay(); }

// Called every frame
void AItem::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);

  // NEW \/
  float MovementRate = 50.f;
  // float RotationRate = 40.f;
  //    AddActorWorldOffset(FVector(MovementRate * DeltaTime, 0.f, 0.f));
  AddActorWorldRotation(FRotator(0.f, RotationRate * DeltaTime, 0.f));
  // RunningTime defined in Item.h
  RunningTime += DeltaTime;
  PerlinValue = FMath::PerlinNoise1D(RunningTime);
  float SineValue = Amplitude * FMath::Sin(RunningTime * TimeConstant);
  AddActorWorldOffset(FVector(0.f, 0.f, SineValue));
  if (GEngine) {
    // FString Name = GetName();
    // FString Message = FString::Printf(TEXT("DeltaTime: %f"), DeltaTime);
    // FString Message = FString::Printf(TEXT("RunningTime: %f"), RunningTime);
    // FString Message = FString::Printf(TEXT("PerlinValue: %f"), PerlinValue);
    // GEngine->AddOnScreenDebugMessage(1, 60.f, FColor::Cyan, Message);
  }
  // end NEW
}
