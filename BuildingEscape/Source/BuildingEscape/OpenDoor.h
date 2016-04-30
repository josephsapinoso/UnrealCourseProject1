// Copyright Joseph Sapinoso 2016

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	UPROPERTY(EditAnywhere) // a macro we set 
	float OpenAngle = 90.0f; // other methods will not be able to set this since it is "private"
		
	UPROPERTY(EditAnywhere) // another macro we are tasked to create
	AActor* PressurePlate; 

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.6f;

	float LastDoorOpenTime;

	AActor* ActorThatOpens; // remember pawn inherits from actor 
	AActor* Owner; // the owning door
};
