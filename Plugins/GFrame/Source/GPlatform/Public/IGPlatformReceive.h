// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Json.h"

/**
 * 
 */
class GPLATFORM_API IGPlatformReceive
{
public:
	virtual TSharedPtr<FJsonObject> ReceiveMessage(int32 Code, TSharedPtr<FJsonObject> Message) = 0;
};
