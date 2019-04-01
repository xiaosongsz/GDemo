// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class GPLATFORM_API IGPlatform
{

public:
	virtual FString SendMessage(const FString &Head, const FString &Message) = 0;
};
