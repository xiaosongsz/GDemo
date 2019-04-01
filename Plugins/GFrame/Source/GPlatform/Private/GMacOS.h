// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IGPlatform.h"
#include "GMacOS.generated.h"

/**
 * 
 */
UCLASS()
class GPLATFORM_API UGMacOS : public UObject, public IGPlatform
{

	GENERATED_BODY()

public:
	virtual FString SendMessage(int32 Code, const FString &Message);
};
