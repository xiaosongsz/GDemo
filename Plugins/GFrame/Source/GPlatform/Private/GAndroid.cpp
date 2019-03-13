// Fill out your copyright notice in the Description page of Project Settings.

#include "GAndroid.h"
#include "GPlatform.h"
#if PLATFORM_ANDROID
#include "AndroidApplication.h"
#include "Async.h"
#include "Stats.h"
#endif

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_xiaosongsz_GPlatform_GPlatform_nativeJava2C(JNIEnv* JNIEnv, jobject LocalThiz, jint code, jstring message)
{
	FString MessageStr;
	const char* javaChars = JNIEnv->GetStringUTFChars(message, 0);
	MessageStr = FString(UTF8_TO_TCHAR(javaChars));
	JNIEnv->ReleaseStringUTFChars(message, javaChars);

	UE_LOG(LogTemp, Log, TEXT("GAndroid:nativeJava2C %s"), &MessageStr);

	DECLARE_CYCLE_STAT(TEXT("FSimpleDelegateGraphTask.STAT_FSimpleDelegateGraphTask_GAndroid"), STAT_FSimpleDelegateGraphTask_GAndroid, STATGROUP_TaskGraphTasks);

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		FGPlatform::GetInstance()->ReceiveMessage(code, MessageStr);
	}),
		GET_STATID(STAT_FSimpleDelegateGraphTask_GAndroid),
		nullptr,
		ENamedThreads::GameThread
		);
}
#endif

FString FGAndroid::SendMessage(int32 Code, const FString &Message)
{
	return TEXT("");
}
