// Fill out your copyright notice in the Description page of Project Settings.


#include "Score.h"
#include "SaveScore.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AScore::AScore()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScore::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AScore::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int AScore::LoadOrCreateSaveGameScore()
{
	auto USaveGame = Cast<USaveScore>(UGameplayStatics::LoadGameFromSlot("BestScore",0));

	if (USaveGame == nullptr)
	{
		USaveGame = Cast<USaveScore>(UGameplayStatics::CreateSaveGameObject(USaveScore::StaticClass()));

		if (USaveGame)
		{
			USaveGame->BestScore = 0;

			UGameplayStatics::SaveGameToSlot(USaveGame,"BestScore",0);

			return 0;
		}
		
	}

	return USaveGame->BestScore;

	
}

void AScore::RenuwalBestScore(int Score)
{
	auto USaveGame = Cast<USaveScore>(UGameplayStatics::LoadGameFromSlot("BestScore",0));

	USaveGame->BestScore = Score;

	UGameplayStatics::SaveGameToSlot(USaveGame,"BestScore",0);
}





