// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GPlatform.h"

UGPlatform* UGPlatform::Instance = nullptr;

UGPlatform* UGPlatform::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = NewObject<UGPlatform>();
		Instance->AddToRoot();
	}
	return Instance;
}

bool UGPlatform::Init(IGPlatform *Platform)
{
	if (this->Platform || !Platform)
	{
		return false;
	}

	this->Platform = Platform;

//#if PLATFORM_ANDROID
	this->Android = NewObject<UGAndroid>(this);
//#endif

	return true;
}

TSharedPtr<FJsonObject> UGPlatform::SendMessage(int32 Code, TSharedPtr<FJsonObject> Message)
{
//#if PLATFORM_ANDROID
	return Android->SendMessage(Code, Message);
//#else
	return nullptr;
//#endif
}

FString UGPlatform::ReceiveMessage(int32 Code, FString Message)
{
	return TEXT("");
}