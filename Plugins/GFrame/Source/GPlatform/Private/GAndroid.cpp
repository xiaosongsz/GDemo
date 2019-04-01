// Fill out your copyright notice in the Description page of Project Settings.

#include "GAndroid.h"
#include "GPlatform.h"
#if PLATFORM_ANDROID
#include "AndroidApplication.h"
#include "Async.h"
#include "Stats.h"
#endif

#if PLATFORM_ANDROID
JNI_METHOD void Java_com_xiaosongsz_GPlatform_GPlatform_nativeJava2C(JNIEnv* JNIEnv, jobject LocalThiz, jstring head, jstring message)
{
	FString MessageStr;
	const char* javaChars = JNIEnv->GetStringUTFChars(message, 0);
	MessageStr = FString(UTF8_TO_TCHAR(javaChars));
	JNIEnv->ReleaseStringUTFChars(message, javaChars);

	FString HeadStr;
	javaChars = JNIEnv->GetStringUTFChars(head, 0);
	HeadStr = FString(UTF8_TO_TCHAR(javaChars));
	JNIEnv->ReleaseStringUTFChars(head, javaChars);

	DECLARE_CYCLE_STAT(TEXT("FSimpleDelegateGraphTask.STAT_FSimpleDelegateGraphTask_GAndroid"), STAT_FSimpleDelegateGraphTask_GAndroid, STATGROUP_TaskGraphTasks);

	FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
		FSimpleDelegateGraphTask::FDelegate::CreateLambda([=]()
	{
		UGPlatform::GetInstance()->ReceiveMessage(HeadStr, MessageStr);
	}),
		GET_STATID(STAT_FSimpleDelegateGraphTask_GAndroid),
		nullptr,
		ENamedThreads::GameThread
		);
}
#endif

FString UGAndroid::SendMessage(const FString &Head, const FString &Message)
{
#if PLATFORM_ANDROID
	JNIEnv* JEnv = FAndroidApplication::GetJavaEnv();
	if (nullptr != JEnv)
	{
		jstring jjson = JEnv->NewStringUTF(TCHAR_TO_UTF8(*Json));

		jclass JGPlatformClass = FAndroidApplication::FindJavaClass("com/xiaosongsz/GPlatform/GPlatform");
		if (JGPlatformClass != nullptr)
		{
			jmethodID methodID = JEnv->GetStaticMethodID(JGPlatformClass, "nativeC2Java", "(Ljava/lang/String;)Ljava/lang/String");
			if (methodID != 0)
			{
				jstring ret = JEnv->CallStaticStringMethod(JGPlatformClass, methodID, jjson);

				FString RetString;
				HeadStr = FString(UTF8_TO_TCHAR(ret));

				return RetString;
			}
		}
	}
#endif

	return TEXT("");
}
