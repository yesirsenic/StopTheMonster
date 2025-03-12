// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnManager.h"
#include "Spawn.h"

// Sets default values
ASpawnManager::ASpawnManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ASpawnManager::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnManager::RandomSpawn, CurrentSpawnTime, false);
}


void ASpawnManager::RandomSpawn()
{
	int32 RandomNumber = FMath::RandRange(0, SpawnedMonsters.Num() - 1);

	ASpawn* Spawn = Cast<ASpawn>(SpawnedMonsters[RandomNumber]);
	Spawn->SpawnMonster(Monster);

	CurrentSpawnTime = FMath::Max(CurrentSpawnTime - DecreaseAmount, MinSpawnTime);
	
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASpawnManager::RandomSpawn, CurrentSpawnTime, false);

	
	
}


