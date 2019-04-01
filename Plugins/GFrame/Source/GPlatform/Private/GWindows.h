// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IGPlatform.h"
#include "GWindows.generated.h"

/**
 * 
 */
UCLASS()
class GPLATFORM_API UGWidnows : public UObject, public IGPlatform
{

	GENERATED_BODY()

public:
	virtual FString SendMessage(const FString &Head, const FString &Message);
};
