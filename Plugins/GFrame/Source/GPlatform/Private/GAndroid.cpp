// Fill out your copyright notice in the Description page of Project Settings.

#include "GAndroid.h"
#include "GPlatform.h"

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_xiaosongsz_GPlatform_GPlatform_nativeJava2C(JNIEnv* JNIEnv, jobject LocalThiz, jint code, jstring message)
{
	FString MessageStr;
	const char* javaChars = JNIEnv->GetStringUTFChars(message, 0);
	MessageStr = FString(UTF8_TO_TCHAR(javaChars));
	JNIEnv->ReleaseStringUTFChars(message, javaChars);

	DECLARE_CYCLE_STAT(TEXT("FSimpleDelegateGraphTask.STAT_FSimpleDelegateGraphTask_GAndroid"), STAT_FSimpleDelegateGraphTask_GAndroid, STATGROUP_TaskGraphTasks);

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		FGPlatform::GetInstance()->ReceiveMessage(code, MessageStr);
	}),
		GET_STATID(STAT_FSimpleDelegateGraphTask_JGAndroid),
		nullptr,
		ENamedThreads::GameThread
		);
}
#endif

FString FGAndroid::SendMessage(int32 Code, FString &Message)
{
	return TEXT("");
}
