#include "DBD_Survivor.h"

#include "Interactable.h"
#include "Kismet/KismetSystemLibrary.h"

ADBD_Survivor::ADBD_Survivor()
{	
}


void ADBD_Survivor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAction("Interact",EInputEvent::IE_Pressed, this, &ADBD_Survivor::Interact);
	PlayerInputComponent->BindAction("Interact",EInputEvent::IE_Released, this, &ADBD_Survivor::StopInteract);
	PlayerInputComponent->BindAxis("MoveForward", this, &ADBD_Survivor::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ADBD_Survivor::MoveRight);
}

void ADBD_Survivor::Interact()
{
	TArray<AActor*> _actorToIgnore;
	FHitResult _hitResult;
	bool _hit = UKismetSystemLibrary::SphereTraceSingleForObjects(this, GetActorLocation(),GetActorLocation(), radiusInteract,objectTypeInteract,false,_actorToIgnore, drawDebug,_hitResult,true);
	if(_hit)
	{
		IInteractable* _interactableObject = Cast<IInteractable>(_hitResult.GetActor());
		if(_interactableObject)
			_interactableObject->Interactable(this);
	}
}

void ADBD_Survivor::StopInteract()
{
		
}

void ADBD_Survivor::MoveForward(float _axis)
{
	if(_axis != 0)
		AddMovementInput(GetActorForwardVector(), _axis);
}

void ADBD_Survivor::MoveRight(float _axis)
{
	if(_axis != 0)
		AddMovementInput(GetActorRightVector(), _axis);
}
