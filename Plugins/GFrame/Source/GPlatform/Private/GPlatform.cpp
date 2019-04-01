// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GPlatform.h"
#if PLATFORM_WINDOWS
#include "GWindows.h"
#elif PLATFORM_ANDROID
#include "GAndroid.h"
#elif PLATFORM_IOS
#include "GIOS.h"
#elif PLATFORM_MAC
#include "GMacOS.h"
#endif

DEFINE_LOG_CATEGORY_STATIC(GPlatform, Log, All);

UGPlatform * UGPlatform::Instance;

UGPlatform * UGPlatform::GetInstance()
{
	if (!Instance)
	{
		Instance = NewObject<UGPlatform>();
		Instance->AddToRoot();
		Instance->Init();
	}

	return Instance;
}

void UGPlatform::Init()
{
#if PLATFORM_WINDOWS
	UGWidnows *GWindows = NewObject<UGWidnows>(this);
	GWindows->AddToRoot();
	Platform = GWindows;
#elif PLATFORM_ANDROID
	UGAndroid *GAndroid = NewObject<UGAndroid>(this);
	GAndroid->AddToRoot();
	Platform = GAndroid;
#elif PLATFORM_IOS
	UGIOS *GIOS = NewObject<UGIOS>(this);
	GIOS->AddToRoot();
	Platform = GIOS;
#elif PLATFORM_MAC
	UGMacOS *GMacOS = NewObject<UGMacOS>(this);
	GMacOS->AddToRoot();
	Platform = GMacOS;
#endif
}

void UGPlatform::RegisterMessage(const FString &Head, IGPlatformMessage *Receive)
{
	Messages.Add(Head, Receive);
}

void UGPlatform::UnRegisterMessage(const FString &Head)
{
	Messages.Remove(Head);
}

TSharedPtr<FJsonObject> UGPlatform::SendMessage(const FString &Head, TSharedPtr<FJsonObject> Message)
{
	return nullptr;
}

void UGPlatform::ReceiveMessage(const FString &Head, const FString &Message)
{
	if (Messages.Find(Head))
	{
		TSharedPtr<FJsonObject> JsonMessage;
		TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Message);
		bool result = FJsonSerializer::Deserialize(Reader, JsonMessage);

		if (result)
		{
			IGPlatformMessage *PlatformMessage = Messages.FindRef(Head);
			PlatformMessage->OnPlatformMessage(JsonMessage);
		}
	}
	else
	{
		UE_LOG(GPlatform, Warning, TEXT("ReceiveMessage:UnRegister %s Message"), &Head);
	}
}
