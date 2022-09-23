#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "DBD_EngineUserWidget.generated.h"


UCLASS(Abstract)
class DBDGAMEPLAY_API UDBD_EngineUserWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UProgressBar* engineFixProgressBar = nullptr;
public:
	void FixProgressUpdate(float _value);
};
