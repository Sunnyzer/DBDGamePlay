#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "GameFramework/Actor.h"
#include "DBD_Engine.generated.h"

UCLASS()
class DBDGAMEPLAY_API ADBD_Engine : public AActor, public IInteractable
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		float currentFixProgressValue = 0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		float maxFixProgressValue = 100;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		float deteriorateRateSpeed = 1;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		float currentBlastProgressValue = 0;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		float maxBlastProgressValue = 100;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
		TArray<TObjectPtr<class ADBD_Survivor>> survivorsCurrentlyFixing;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
		UStaticMeshComponent* staticMesh; 
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
		class UDBD_QtePeriodicComponent* qteComponent = nullptr;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
		TSubclassOf<class UDBD_EngineUserWidget> engineClassWidget;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
		class UDBD_EngineUserWidget* engineWidget = nullptr;
public:	
	ADBD_Engine();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
public:
	UFUNCTION(BlueprintCallable)
		void AddFix(float _value);
	UFUNCTION(BlueprintCallable)
		void RemoveFix(float value);
	UFUNCTION(BlueprintCallable)
		void EngineBlast();
	UFUNCTION(BlueprintCallable)
		void AddFixOnSuccessQte();
	void Interactable(class ADBD_Character* _character);
	UFUNCTION(BlueprintCallable)
		void StopInteractable(class ADBD_Survivor* _survivor);
};
