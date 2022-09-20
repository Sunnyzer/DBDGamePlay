// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DBD_Character.generated.h"

UCLASS()
class DBDGAMEPLAY_API ADBD_Character : public ACharacter
{
	GENERATED_BODY()

public:
	ADBD_Character();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
