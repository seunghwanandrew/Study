#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class STUDY_API AItem : public AActor
{
	GENERATED_BODY()
#pragma region Constructor and Function
public:
	AItem();
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintPure)
	float TransformedSin();
	UFUNCTION(BlueprintPure)
	float TransformedCos();
	template<typename T>
	T Average(T FirstValue, T SecondValue);
#pragma endregion

#pragma region Variable
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float Amplitude = 0.25f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Sine Parameters")
	float TimeConstant = 5.0f;
#pragma endregion


};

template<typename T>
inline T AItem::Average(T FirstValue, T SecondValue)
{
	return (FirstValue + SecondValue) * 0.5f;
}
