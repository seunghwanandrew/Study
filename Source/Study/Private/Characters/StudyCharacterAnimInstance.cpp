#include "Characters/StudyCharacterAnimInstance.h"
#include "Characters/StudyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UStudyCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	StudyCharacter = Cast<AStudyCharacter>(TryGetPawnOwner());
	if (StudyCharacter)
	{
		StudyCharacterMovement = StudyCharacter->GetCharacterMovement();
	}
}

void UStudyCharacterAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if (StudyCharacterMovement)
	{
		FVector VelocityValue = StudyCharacterMovement->Velocity;
		GroundSpeed = FMath::Sqrt((VelocityValue.X * VelocityValue.X) + (VelocityValue.Y * VelocityValue.Y));
		//GroundSpeed = UKismetMathLibrary::VSizeXY(StudyCharacterMovement->Velocity);
		IsFalling = StudyCharacterMovement->IsFalling();
		CharacterState = StudyCharacter->GetCharacterState();
	}
}
