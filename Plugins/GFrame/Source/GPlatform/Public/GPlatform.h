// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Json.h"
#include "IGPlatform.h"
#include "IGPlatformMessage.h"
#include "GPlatform.generated.h"

/**
 *
 */
UCLASS()
class GPLATFORM_API UGPlatform : public UObject
{
	GENERATED_BODY()

protected:

	static UGPlatform *Instance;

public:

	static UGPlatform *GetInstance();

public:

	void Init();

	void RegisterMessage(const FString &Head, IGPlatformMessage *Receive);

	void UnRegisterMessage(const FString &Head);

	TSharedPtr<FJsonObject> SendMessage(const FString &Head, TSharedPtr<FJsonObject> Message);

	void ReceiveMessage(const FString &Head, const FString &Message);

protected:
	IGPlatform *Platform;

	TMap<FString, IGPlatformMessage*> Messages;
};