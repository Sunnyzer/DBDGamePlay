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
		currentWidgetDisplay->QteSliderUpdate(timerQte);
		if(timerQte > timeMaxQte)
		{
			currentIntervalToPressed = 0;
			StopQte();
			return;
		}
		FIntervalToPressedInput _currentInterval = allIntervalInputs[currentIntervalToPressed];
		if(_currentInterval.intervalFinish < timerQte)
		{
			if(currentIntervalToPressed >= allIntervalInputs.Num() - 1) return;
			currentIntervalToPressed++;
		}
		if(GetWorld()->GetFirstPlayerController()->IsInputKeyDown(_currentInterval.key))
		{
			if(_currentInterval.intervalStart < timerQte)
			{
				onQteSuccess.Broadcast();
				StopQte();
				return;
			}
			if(_currentInterval.intervalStart > timerQte || _currentInterval.intervalFinish < timerQte)
			{
				onQteFailed.Broadcast();
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
	if(canAppeared)return;
	ResetRandomizeTimeBetweenQte();
	canAppeared = true;
}

void UDBD_QtePeriodicComponent::StopQte()
{
	timerQte = 0;
	canAppeared = false;
	if(!currentWidgetDisplay) return;
	
	currentWidgetDisplay->RemoveFromViewport();
	currentWidgetDisplay = nullptr;
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
	currentWidgetDisplay->QteInterval(allIntervalInputs[0].intervalStart,allIntervalInputs[0].intervalFinish);
	currentWidgetDisplay->AddToViewport();
}
