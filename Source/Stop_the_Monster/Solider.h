// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Solider.generated.h"

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	Idle        UMETA(DisplayName = "Idle"),
	Running     UMETA(DisplayName = "Running"),
	Attacking   UMETA(DisplayName = "Attacking"),
	Jumping     UMETA(DisplayName = "Jumping")
};


UCLASS()
class STOP_THE_MONSTER_API ASolider : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASolider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	

	UFUNCTION(BlueprintCallable, Category = "State")
	void SetState(ECharacterState NewState);

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "State", meta = (AllowPrivateAccess = "true"))
	bool IsRuning = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "State", meta = (AllowPrivateAccess = "true"))
	bool IsAttacking = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "State", meta = (AllowPrivateAccess = "true"))
	bool IsJumping = false;

	ECharacterState CurrentState = ECharacterState::Idle;

	

	

};
