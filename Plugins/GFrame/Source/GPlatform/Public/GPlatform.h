// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IGPlatform.h"

class FJsonObject;
class IGPlatformMessage;

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

	~FGPlatform();

	FGPlatform();

public:

	void RegisterMessage(IGPlatformMessage *Receive);

	void UnRegisterMessage(IGPlatformMessage *Receive);

	TSharedPtr<FJsonObject> SendMessage(int32 Code, TSharedPtr<FJsonObject> Message);

	void ReceiveMessage(int32 Code, const FString &Message);

protected:

	TArray<IGPlatformMessage*> Messages;

	TSharedPtr<IGPlatform> Platform;
};