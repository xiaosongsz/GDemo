// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IGPlatform.h"

/**
 * 
 */
class GPLATFORM_API FGMac : public IGPlatform
{

public:
	virtual FString SendMessage(int32 Code, const FString &Message);
};
