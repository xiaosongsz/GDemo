// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

typedef TFunction<FString(int32, FString)> FPlatformReceive;

/**
 * 
 */
class GPLATFORM_API GReceive
{
public:
	virtual void SetReceiveFunction(FPlatformReceive ReceiveFunction) 
	{
		this->ReceiveFunction = ReceiveFunction;
	}

protected:
	FPlatformReceive ReceiveFunction;
};
