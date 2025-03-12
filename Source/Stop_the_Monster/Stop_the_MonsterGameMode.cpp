// Copyright Epic Games, Inc. All Rights Reserved.

#include "Stop_the_MonsterGameMode.h"
#include "Stop_the_MonsterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AStop_the_MonsterGameMode::AStop_the_MonsterGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
