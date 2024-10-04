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
		GroundSpeed = UKismetMathLibrary::VSizeXY(StudyCharacterMovement->Velocity);
		IsFalling = StudyCharacterMovement->IsFalling();
	}
}
