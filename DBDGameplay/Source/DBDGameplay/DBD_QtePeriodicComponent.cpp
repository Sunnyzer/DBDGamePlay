#include "DBD_QtePeriodicComponent.h"
#include "Blueprint/UserWidget.h"
#include "DBD_QteWidget.h"

UDBD_QtePeriodicComponent::UDBD_QtePeriodicComponent()
{
}

void UDBD_QtePeriodicComponent::TickComponent(float DeltaTime, ELevelTick TickType,	FActorComponentTickFunction* ThisTickFunction)
{
	if(currentWidgetDisplay)
	{
		timerQte += DeltaTime * 0.4f;
		FIntervalToPressedInput _currentInterval = allIntervalInputs[currentIntervalToPressed];
		if(_currentInterval.intervalFinish < timerQte)
		{
			currentIntervalToPressed++;
			if(currentIntervalToPressed > allIntervalInputs.Num() - 1)
			{
				currentIntervalToPressed = 0;
				StopQte();
			}
		}
		if(GetWorld()->GetFirstPlayerController()->IsInputKeyDown(_currentInterval.key))
		{
			if(_currentInterval.intervalStart < timerQte)
			{
				onQteSuccess.Broadcast();
				GEngine->AddOnScreenDebugMessage(1,2,FColor::Black,TEXT("SuccessQte"));
				StopQte();
			}
		}
		return;
	}
	if(!canAppeared) return;
	timerQte += DeltaTime;
	if(timerQte > (isRandomizeTimeBetweenQte ? currentTimeBetweenQte : timeBetweenQte))
	{
		SpawnQte();
		ResetRandomizeTimeBetweenQte();
	}
}

void UDBD_QtePeriodicComponent::StartQte()
{
	ResetRandomizeTimeBetweenQte();
	canAppeared = true;
}

void UDBD_QtePeriodicComponent::StopQte()
{
	currentWidgetDisplay->RemoveFromViewport();
	currentWidgetDisplay = nullptr;
	canAppeared = false;
}

void UDBD_QtePeriodicComponent::ResetQte()
{
}

int UDBD_QtePeriodicComponent::ResetRandomizeTimeBetweenQte()
{
	timerQte = 0;
	currentTimeBetweenQte = rand() % (maxRandomizeTime - minRandomizeTime) + minRandomizeTime;
	return currentTimeBetweenQte;
}

void UDBD_QtePeriodicComponent::SpawnQte()
{
	currentWidgetDisplay = CreateWidget<UDBD_QteWidget>(GetWorld(), widgetQte);
	currentWidgetDisplay->AddToViewport();
}
