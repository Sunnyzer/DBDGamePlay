// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DBD_Character.h"
#include "DBD_Survivor.generated.h"

/**
 * 
 */
UCLASS()
class DBDGAMEPLAY_API ADBD_Survivor : public ADBD_Character
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float repareSpeed = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<TEnumAsByte<EObjectTypeQuery>> objectInteract;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		class ADBD_Engine* currentEngine;
public:
	ADBD_Survivor();
public:
	FORCEINLINE float GetRepareSpeedValue() const { return repareSpeed; }
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	UFUNCTION(BlueprintCallable)
		void Interact();
	UFUNCTION(BlueprintCallable)
		void StopInteract();
};
