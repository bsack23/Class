// Fill out your copyright notice in the Description page of Project Settings.

#include "Pawns/Bird.h"
// include these headers because of forward declaration
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values 
// This is the class constructor! runs once when we make a new instance of the class
ABird::ABird() {
  // Set this pawn to call Tick() every frame.  You can turn this off to improve
  // performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;
  // this creates the Capsule based on UCapsuleComponent template
  Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
  // and sets it as the root component
  SetRootComponent(Capsule);
  // again, take the pointer from Bird.h and create the skeletal mesh 
  BirdMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BirdMesh"));
  // attach it to the Root Component so they all move together
  BirdMesh->SetupAttachment(GetRootComponent());

  // make Player0 possess this pawn - E means its an enum
  AutoPossessPlayer = EAutoReceiveInput::Player0;

  SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
  SpringArm->SetupAttachment(Capsule);
  SpringArm->TargetArmLength = 300.f;

  ViewCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("ViewCamera"));
  ViewCamera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void ABird::BeginPlay() { Super::BeginPlay(); }

// Called every frame
void ABird::Tick(float DeltaTime) { Super::Tick(DeltaTime); }

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent) {
  Super::SetupPlayerInputComponent(PlayerInputComponent);
}
