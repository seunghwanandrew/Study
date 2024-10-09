#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "Weapon.generated.h"

UCLASS()
class STUDY_API AWeapon : public AItem
{
	GENERATED_BODY()
#pragma region Constructor and Function
private:
protected:
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
public:
	void Equip(USceneComponent* InParent, FName InSocketName);
#pragma endregion

#pragma region Variable
private:
protected:
#pragma endregion
};
