#include "DBD_EngineUserWidget.h"

void UDBD_EngineUserWidget::FixProgressUpdate(float _value)
{
	engineFixProgressBar->SetPercent(_value);
}
