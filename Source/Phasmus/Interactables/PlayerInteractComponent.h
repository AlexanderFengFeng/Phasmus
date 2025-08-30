#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "PlayerInteractComponent.generated.h"

class AInteractable;
class APhasmusPlayerCharacter;
class UCameraComponent;

// A scene component that detects overlaps with
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PHASMUS_API UPlayerInteractComponent : public USphereComponent
{
	GENERATED_BODY()

public:
	UPlayerInteractComponent();

	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintPure)
	AInteractable* GetCurrentInteractable() const { return TracedInteractable; }
	
protected:
	UPROPERTY(EditAnywhere)
	float DetectionDistance = 100.f;

	UPROPERTY(EditAnywhere)
	float DetectionRadius = 14.0f;

	UPROPERTY(EditAnywhere, Category = Components)
	UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(BlueprintReadOnly, Transient)
	TObjectPtr<AInteractable> TracedInteractable;

	UPROPERTY(BlueprintReadOnly, Transient)
	TObjectPtr<APhasmusPlayerCharacter> PlayerOwner;

protected:
    void ShowInteractPromptIfNeeded();

	void TraceForInteractable();
};
