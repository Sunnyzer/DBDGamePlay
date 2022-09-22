#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/Slider.h"
#include "DBD_QteWidget.generated.h"

/**
 * 
 */
UCLASS()
class DBDGAMEPLAY_API UDBD_QteWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		USlider* qteSlider = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (BindWidget))
		UProgressBar* qteProgressBar = nullptr;
public:
	void QteSliderUpdate(float _value);
	void QteInterval(float _intervalMin ,float _intervalMax);
};
