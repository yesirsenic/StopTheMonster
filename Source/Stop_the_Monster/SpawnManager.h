// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnManager.generated.h"

UCLASS()
class STOP_THE_MONSTER_API ASpawnManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly,Category = "Spawn" , meta = (AllowPrivateAccess = "true"))
	TArray<AActor*> SpawnedMonsters;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = "Spawn" , meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ACharacter> Monster;
	
	void RandomSpawn();

	FTimerHandle SpawnTimerHandle;
	float CurrentSpawnTime = 3.f;
	float MinSpawnTime = 1.5f;
	float DecreaseAmount = 0.05f;
	

};
