// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputCoreTypes.h"
#include "DBD_QteComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQteFinish);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQteSuccess);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnQteFailed);

USTRUCT(BlueprintType)
struct FIntervalToPressedInput
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Time",BlueprintReadWrite)
		float intervalStart = 0;
	UPROPERTY(EditAnywhere, Category = "Time",BlueprintReadWrite)
		float intervalFinish = 0;
	UPROPERTY(EditAnywhere, Category = "Time",BlueprintReadWrite)
		FKey key;
};
UCLASS(Abstract,Blueprintable)
class DBDGAMEPLAY_API UDBD_QteComponent : public UActorComponent
{
	GENERATED_BODY()
protected:
	UPROPERTY(BlueprintAssignable)
		FOnQteFinish onQteFinish;
	UPROPERTY(BlueprintAssignable)
		FOnQteSuccess onQteSuccess;
	UPROPERTY(BlueprintAssignable)
		FOnQteFailed onQteFailed;
	UPROPERTY(EditAnywhere, Category = "Qte", BlueprintReadWrite)
		TSubclassOf<class UDBD_QteWidget> widgetQte = nullptr;
	UPROPERTY(VisibleAnywhere, Category = "Qte",BlueprintReadWrite)
		bool isTryingQte = false;
	UPROPERTY(EditAnywhere, Category = "Qte",BlueprintReadWrite)
		TArray<FIntervalToPressedInput> allIntervalInputs;
public:	
	UDBD_QteComponent();
public:
	FOnQteFailed& OnQteFailed() { return onQteFailed; }
	FOnQteSuccess& OnQteSuccess() { return onQteSuccess; }
	FOnQteFinish& OnQteFinish() { return onQteFinish; }
protected:
	UFUNCTION(BlueprintCallable)
	virtual void StartQte() {};
	UFUNCTION(BlueprintCallable)
	virtual void StopQte() {};
	UFUNCTION(BlueprintCallable)
	virtual void ResetQte() {};
		
};
