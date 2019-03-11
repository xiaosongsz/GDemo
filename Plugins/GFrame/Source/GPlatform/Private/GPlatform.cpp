// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GPlatform.h"
#include "Android/GAndroid.h"

FGPlatform* FGPlatform::Instance = nullptr;

FGPlatform* FGPlatform::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new FGPlatform();
		Instance->Init();
	}

	return Instance;
}

void FGPlatform::DestroyInstance()
{
	if (Instance != nullptr)
	{
		delete Instance;
		Instance = nullptr;
	}
}

TSharedPtr<FJsonObject> FGPlatform::SendMessage(int32 Code, TSharedPtr<FJsonObject> Message)
{
	return nullptr;
}

void FGPlatform::RegisterReceive(IGPlatformReceive *Receive)
{
	this->ReceiveArray->Push(Receive);
}

void FGPlatform::Init()
{
	this->ReceiveArray = MakeShareable(new TArray<IGPlatformReceive*>());
}
