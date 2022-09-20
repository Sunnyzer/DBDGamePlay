// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DBD_Character.h"
#include "DBD_Survivor.generated.h"

namespace EDrawDebugTrace
{
	enum Type;
}

UCLASS()
class DBDGAMEPLAY_API ADBD_Survivor : public ADBD_Character
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float repareSpeed = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float radiusInteract = 100;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TEnumAsByte<EObjectTypeQuery>> objectTypeInteract;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TEnumAsByte<EDrawDebugTrace::Type> drawDebug;
public:
	ADBD_Survivor();
public:
	float GetRepareSpeedValue() const { return repareSpeed; }
protected:
	UFUNCTION(BlueprintCallable)
		void Interact();
	UFUNCTION(BlueprintCallable)
		void StopInteract();
	UFUNCTION(BlueprintCallable)
		void MoveForward(float _axis); 
	UFUNCTION(BlueprintCallable)
		void MoveRight(float _axis); 
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
};
