#include "DBD_Survivor.h"

#include "DBD_Engine.h"
#include "Interactable.h"
#include "Kismet/KismetSystemLibrary.h"

ADBD_Survivor::ADBD_Survivor()
{	
}

void ADBD_Survivor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Interact",IE_Pressed, this, &ADBD_Survivor::Interact);
	PlayerInputComponent->BindAction("Interact",IE_Released, this, &ADBD_Survivor::StopInteract);
}

void ADBD_Survivor::Interact()
{
	FHitResult _hitResult;
	TArray<AActor*> _toIgnore;
	bool _hit = UKismetSystemLibrary::SphereTraceSingleForObjects(this ,GetActorLocation(),GetActorLocation(),100,objectInteract,false ,_toIgnore, EDrawDebugTrace::None,_hitResult,true);
	if(_hit)
	{
		 ADBD_Engine* _engine = Cast<ADBD_Engine>(_hitResult.GetActor());
		if(_engine)
		{
			_engine->Interactable(this);
			currentEngine = _engine;
		}
	}
}

void ADBD_Survivor::StopInteract()
{
	if (!currentEngine)return;	
	currentEngine->StopInteractable(this);
	currentEngine = nullptr;
}
