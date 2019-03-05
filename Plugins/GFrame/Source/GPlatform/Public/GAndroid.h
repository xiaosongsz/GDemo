// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GAndroid.generated.h"

/**
 * 
 */
UCLASS()
class GPLATFORM_API UGAndroid : public UObject
{
	GENERATED_BODY()
public:
	TSharedPtr<FJsonObject> SendMessage(int32 Code, TSharedPtr<FJsonObject> Message);

	FString ReceiveMessage(int32 Code, FString Message);
};
