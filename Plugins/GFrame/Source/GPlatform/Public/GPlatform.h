// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IGPlatform.h"
#include "UObject/NoExportTypes.h"
//#if PLATFORM_ANDROID
	#include "GAndroid.h"
//#endif
#include "GPlatform.generated.h"

/**
 *
 */
UCLASS()
class GPLATFORM_API UGPlatform : public UObject
{
	GENERATED_BODY()

protected:
	static UGPlatform* Instance;

public:
	static UGPlatform* GetInstance();

public:
	bool Init(IGPlatform *Platform);

	TSharedPtr<FJsonObject> SendMessage(int32 Code, TSharedPtr<FJsonObject> Message);

	FString ReceiveMessage(int32 Code, FString Message);

protected:
	IGPlatform *Platform;

//#if PLATFORM_ANDROID
	UPROPERTY()
		UGAndroid *Android;
//#endif
};