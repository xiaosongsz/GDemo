// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

class FJsonObject;

/**
 * 
 */
class GPLATFORM_API IGPlatformMessage
{
public:
	virtual TSharedPtr<FJsonObject> OnPlatformMessage(int32 Code, TSharedPtr<FJsonObject> Message) = 0;
};
