#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CharacterTypes.h"
#include "StudyCharacterAnimInstance.generated.h"

class AStudyCharacter;
class UCharacterMovementComponent;

UCLASS()
class STUDY_API UStudyCharacterAnimInstance : public UAnimInstance
{
#pragma region Constructor and Function
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTime) override;
#pragma endregion

#pragma region Variable
public:
	UPROPERTY(BlueprintReadOnly)
	AStudyCharacter* StudyCharacter;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	UCharacterMovementComponent* StudyCharacterMovement;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	float GroundSpeed;
	UPROPERTY(BlueprintReadOnly, Category = Movement)
	bool IsFalling;
	UPROPERTY(BlueprintReadOnly, Category = "Movement | Character State")
	ECharacterState CharacterState;

#pragma endregion
};
