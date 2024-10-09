#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

class USphereComponent;

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

	// Create Delegate
	UFUNCTION(BlueprintCallable)
	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, 
		UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION(BlueprintCallable)
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

#pragma endregion

#pragma region Variable
private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float RunningTime;
	UPROPERTY(VisibleAnywhere)
	USphereComponent* Sphere;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* ItemMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float Amplitude = 0.25f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Sine Parameters")
	float TimeConstant = 5.0f;
#pragma endregion

};
