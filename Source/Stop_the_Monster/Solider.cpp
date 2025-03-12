// Fill out your copyright notice in the Description page of Project Settings.


#include "Solider.h"

// Sets default values
ASolider::ASolider()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASolider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASolider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASolider::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASolider::SetState(ECharacterState NewState)
{
	if (NewState == ECharacterState::Jumping)
	{
		if (IsAttacking)
			return;
		CurrentState = NewState;
		IsJumping = true;
		IsRuning = false;
		IsAttacking = false;
	}

	else if (NewState == ECharacterState::Attacking)
	{
		if (IsJumping)
			return;
		CurrentState = NewState;
		IsAttacking = true;
		IsRuning = false;
	}

	else if (NewState == ECharacterState::Running)
	{
		if (IsJumping || IsAttacking)
			return;
		CurrentState = NewState;
		IsRuning = true;
	}

	else
	{
		CurrentState = ECharacterState::Idle;
	}
}


