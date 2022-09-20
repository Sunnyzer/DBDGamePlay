#pragma once

#include "CoreMinimal.h"
#include "DBD_QteComponent.h"
#include "DBD_QtePeriodicComponent.generated.h"

UCLASS(Blueprintable, meta = (BlueprintSpawnableComponent))
class DBDGAMEPLAY_API UDBD_QtePeriodicComponent : public UDBD_QteComponent
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Qte",meta = (EditCondition = "isRandomizeTimeBetweenQte"))
		int maxRandomizeTime = 4;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Qte", meta = (EditCondition = "isRandomizeTimeBetweenQte"))
		int minRandomizeTime = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Qte", meta = (EditCondition = "!isRandomizeTimeBetweenQte"))
		float timeBetweenQte = 1;
	UPROPERTY(EditAnywhere, Category = "Qte", BlueprintReadWrite)
		bool isRandomizeTimeBetweenQte = false; 
	UPROPERTY(VisibleAnywhere, Category = "Qte", BlueprintReadWrite)
		int currentTimeBetweenQte = 0;
	UPROPERTY(VisibleAnywhere, Category = "Qte", BlueprintReadWrite)
		int timerQte = 0;
	UPROPERTY(VisibleAnywhere, Category = "Qte", BlueprintReadWrite)
		int currentIntervalToPressed = 0;
	UPROPERTY(VisibleAnywhere, Category = "Qte", BlueprintReadWrite)
		bool canAppeared = false;
	UPROPERTY()
		class UDBD_QteWidget* currentWidgetDisplay = nullptr;
public:
	UDBD_QtePeriodicComponent();
protected:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
public:
	virtual void StartQte() override;
	virtual void StopQte() override;
	virtual void ResetQte() override;
	UFUNCTION(BlueprintCallable)
		int ResetRandomizeTimeBetweenQte();
	UFUNCTION(BlueprintCallable)
		void SpawnQte();
};
