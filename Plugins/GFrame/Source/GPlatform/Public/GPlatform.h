// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IGPlatformReceive.h"

/**
 *
 */
class GPLATFORM_API FGPlatform
{
protected:
	static FGPlatform* Instance;

public:
	static FGPlatform* GetInstance();

	static void DestroyInstance();

private:
	FGPlatform() {};

	~FGPlatform() {};

public:
	TSharedPtr<FJsonObject> SendMessage(int32 Code, TSharedPtr<FJsonObject> Message);

	void RegisterReceive(IGPlatformReceive *Receive);

protected:
	void Init();

protected:
	TSharedPtr<TArray<IGPlatformReceive*>> ReceiveArray;
};