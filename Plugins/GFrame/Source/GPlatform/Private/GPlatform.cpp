// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "GPlatform.h"
#include "Json.h"
#include "IGPlatformMessage.h"
#include "Android/GAndroid.h"

FGPlatform* FGPlatform::Instance = nullptr;

FGPlatform* FGPlatform::GetInstance()
{
	if (Instance == nullptr)
	{
		Instance = new FGPlatform();
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

FGPlatform::~FGPlatform()
{

}

FGPlatform::FGPlatform()
{
	//Platform = MakeShareable(new FGAndroid());
}

void FGPlatform::RegisterMessage(IGPlatformMessage *Receive)
{
	Messages.Add(Receive);
}

void FGPlatform::UnRegisterMessage(IGPlatformMessage *Receive)
{
	Messages.Remove(Receive);
}

TSharedPtr<FJsonObject> FGPlatform::SendMessage(int32 Code, TSharedPtr<FJsonObject> Message)
{
	FString MessageStr;
	TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&MessageStr);
	bool result = FJsonSerializer::Serialize(Message.ToSharedRef(), Writer);

	TSharedPtr<FJsonObject> RetJsonObject = MakeShareable(new FJsonObject());

	if (result && Platform.IsValid())
	{
		//FString RetStr = Platform->SendMessage(Code, MessageStr);
		
		//TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(RetStr);
		//FJsonSerializer::Deserialize(Reader, RetJsonObject);
	}

	return RetJsonObject;
}
