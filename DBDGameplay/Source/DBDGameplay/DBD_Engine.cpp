#include "DBD_Engine.h"
#include "DBD_Character.h"
#include "DBD_QteComponent.h"
#include "DBD_QtePeriodicComponent.h"
#include "DBD_Survivor.h"


ADBD_Engine::ADBD_Engine()
{
	PrimaryActorTick.bCanEverTick = true;
	staticMesh = CreateDefaultSubobject<UStaticMeshComponent>("staticMesh");
	qteComponent = CreateDefaultSubobject<UDBD_QtePeriodicComponent>("QtePeriodicComponent");
}


void ADBD_Engine::BeginPlay()
{
	Super::BeginPlay();
	qteComponent->OnQteSuccess().AddDynamic(this, &ADBD_Engine::AddFixOnSuccessQte);
}

void ADBD_Engine::Tick(float DeltaTime)
{
	const int count = survivorsCurrentlyFixing.Num();
	for (int i = 0; i < count; i++)
	{
		AddFix(survivorsCurrentlyFixing[i]->GetRepareSpeedValue() * DeltaTime);
	}
	if(count != 0)
	{
		qteComponent->StartQte();
		GEngine->AddOnScreenDebugMessage(-1,0,FColor::Black,"startQte");
	}
}

void ADBD_Engine::AddFix(float _value)
{
	currentFixProgressValue += _value;
}

void ADBD_Engine::RemoveFix(float _value)
{
	currentFixProgressValue -= _value;
}

void ADBD_Engine::EngineBlast()
{
	
}

void ADBD_Engine::AddFixOnSuccessQte()
{
	AddFix(1);
}

void ADBD_Engine::Interactable(ADBD_Character* _character)
{
	ADBD_Survivor* _survivor = Cast<ADBD_Survivor>(_character);
	GEngine->AddOnScreenDebugMessage(-1,2,FColor::Black,"cast survivor");
	if(!_survivor)return;
	survivorsCurrentlyFixing.Add(_survivor);
	GEngine->AddOnScreenDebugMessage(-1,2,FColor::Black,"Addsurvivor");
}

void ADBD_Engine::StopInteractable(ADBD_Survivor* _survivor)
{
	survivorsCurrentlyFixing.Remove(_survivor);
	qteComponent->StopQte();
}

