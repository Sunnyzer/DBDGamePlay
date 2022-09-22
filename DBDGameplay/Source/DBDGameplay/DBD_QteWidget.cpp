// Fill out your copyright notice in the Description page of Project Settings.


#include "DBD_QteWidget.h"

#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/CanvasPanelSlot.h"

void UDBD_QteWidget::QteSliderUpdate(float _value)
{
	qteSlider->SetValue(_value);
}

void UDBD_QteWidget::QteInterval(float _intervalMin, float _intervalMax)
{
	const FString _message = FString::Printf(TEXT("%f"), qteProgressBar->GetDesiredSize().X);
	GEngine->AddOnScreenDebugMessage(-1,0.5f,FColor::Red,_message);
	qteProgressBar->BorderPadding.X = UWidgetLayoutLibrary::SlotAsCanvasSlot(qteProgressBar)->GetSize().X * _intervalMin;
	qteProgressBar->Percent = _intervalMax;
}
