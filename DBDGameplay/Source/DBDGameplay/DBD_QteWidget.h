// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
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
	UPROPERTY(meta = (BindWidget))
		USlider* qteSlider;
	UPROPERTY(meta = (BindWidget))
		UProgressBar* qteProgressBar;
public:
	
};
