// Fill out your copyright notice in the Description page of Project Settings.

#include "Pawns/Bird.h"
// #include "Components/CapsuleComponent.h"

// Sets default values 
// This is the class constructor! runs once when we make a new instance of the class
ABird::ABird() {
  // Set this pawn to call Tick() every frame.  You can turn this off to improve
  // performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
  // this adds the Capsule 
  Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
  // and sets it as the root component
  SetRootComponent(Capsule);
}

// Called when the game starts or when spawned
void ABird::BeginPlay() { Super::BeginPlay(); }

// Called every frame
void ABird::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);
}
