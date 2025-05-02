#pragma once

// UE-style Enum to set character state
UENUM(BlueprintType)
enum class ECharacterState : uint8 {
  ECS_Unequipped UMETA(DisplayName = "Unequipped"),
  ECS_EquippedOneHandedUtensil UMETA(DisplayName =
                                         "Equipped One-Handed Utensil"),
  ECS_EquippedTwoHandedUtensil UMETA(DisplayName =
                                         "Equipped Two-Handed Utensil")
};
// and whether it's swinging utensil or not
UENUM(BlueprintType)
enum class EActionState : uint8 {
  EAS_Unoccupied UMETA(DisplayName = "Unoccupied"),
  EAS_Swinging UMETA(DisplayName = "Swinging")
};