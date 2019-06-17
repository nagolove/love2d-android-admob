/**
 * Copyright (c) 2006-2016 LOVE Development Team
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * arising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 **/
 
 /**
 *This file has been edited by bio1712 for love2d.org
 **/

#include "android_ads.h"

#ifdef LOVE_ANDROID

#include "SDL.h"
#include "jni.h"

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

namespace love
{
namespace android
{
//Ads

void createBanner(const char *adID,const char *position)
{
	std::string ID = (std::string) adID;
	std::string pos = (std::string) position;
	
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();
	jclass clazz (env->GetObjectClass(activity));

	jmethodID method_id = env->GetMethodID(clazz, "createBanner", "(Ljava/lang/String;Ljava/lang/String;)V");
	jstring ID_jstring = (jstring) env->NewStringUTF(ID.c_str());
	jstring pos_jstring = (jstring) env->NewStringUTF(pos.c_str());

	env->CallVoidMethod(activity, method_id, ID_jstring, pos_jstring);

	env->DeleteLocalRef(ID_jstring);
	env->DeleteLocalRef(pos_jstring);
	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);
}

	
void hideBanner()
{
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();
	jclass clazz (env->GetObjectClass(activity));

	jmethodID method_id = env->GetMethodID(clazz, "hideBanner", "()V");

	env->CallVoidMethod(activity, method_id);
	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);
}
	
void showBanner()
{
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();
	jclass clazz (env->GetObjectClass(activity));

	jmethodID method_id = env->GetMethodID(clazz, "showBanner", "()V");

	env->CallVoidMethod(activity, method_id);
	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);
}

void requestInterstitial(const char *adID)
{
	std::string ID = (std::string) adID;
	
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();
	jclass clazz (env->GetObjectClass(activity));

	jmethodID method_id = env->GetMethodID(clazz, "requestInterstitial", "(Ljava/lang/String;)V");
	jstring ID_jstring = (jstring) env->NewStringUTF(ID.c_str());

	env->CallVoidMethod(activity, method_id, ID_jstring);

	env->DeleteLocalRef(ID_jstring);
	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);
}

bool isInterstitialLoaded()
{
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();

	jclass clazz(env->GetObjectClass(activity));
	jmethodID method_id = env->GetMethodID(clazz, "isInterstitialLoaded", "()Z");

	jboolean adLoaded = env->CallBooleanMethod(activity, method_id);

	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);

	return adLoaded;
}

void showInterstitial()
{
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();
	jclass clazz (env->GetObjectClass(activity));

	jmethodID method_id = env->GetMethodID(clazz, "showInterstitial", "()V");

	env->CallVoidMethod(activity, method_id);
	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);
}


void requestRewardedAd(const char *adID)
{
	std::string ID = (std::string) adID;
	
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();
	jclass clazz (env->GetObjectClass(activity));

	jmethodID method_id = env->GetMethodID(clazz, "requestRewardedAd", "(Ljava/lang/String;)V");
	jstring ID_jstring = (jstring) env->NewStringUTF(ID.c_str());

	env->CallVoidMethod(activity, method_id, ID_jstring);

	env->DeleteLocalRef(ID_jstring);
	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);
}

bool isRewardedAdLoaded()
{
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();

	jclass clazz(env->GetObjectClass(activity));
	jmethodID method_id = env->GetMethodID(clazz, "isRewardedAdLoaded", "()Z");

	jboolean adLoaded = env->CallBooleanMethod(activity, method_id);

	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);

	return adLoaded;
}

void showRewardedAd()
{
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();
	jclass clazz (env->GetObjectClass(activity));

	jmethodID method_id = env->GetMethodID(clazz, "showRewardedAd", "()V");

	env->CallVoidMethod(activity, method_id);
	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);
}

//For callbacks

bool coreInterstitialError()
{
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();

	jclass clazz(env->GetObjectClass(activity));
	jmethodID method_id = env->GetMethodID(clazz, "coreInterstitialError", "()Z");

	jboolean adHasFailedToLoad = env->CallBooleanMethod(activity, method_id);

	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);

	return adHasFailedToLoad;
}

bool coreInterstitialClosed()
{
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();

	jclass clazz(env->GetObjectClass(activity));
	jmethodID method_id = env->GetMethodID(clazz, "coreInterstitialClosed", "()Z");

	jboolean adHasBeenClosed = env->CallBooleanMethod(activity, method_id);

	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);

	return adHasBeenClosed;
}

bool coreRewardedAdError()
{
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();

	jclass clazz(env->GetObjectClass(activity));
	jmethodID method_id = env->GetMethodID(clazz, "coreRewardedAdError", "()Z");

	jboolean adHasFailedToLoad = env->CallBooleanMethod(activity, method_id);

	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);

	return adHasFailedToLoad;
}

bool coreRewardedAdDidStop()
{
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();

	jclass clazz(env->GetObjectClass(activity));
	jmethodID method_id = env->GetMethodID(clazz, "coreRewardedAdDidStop", "()Z");

	jboolean adHasBeenClosed = env->CallBooleanMethod(activity, method_id);

	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);

	return adHasBeenClosed;
}

bool coreRewardedAdDidFinish()
{
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();

	jclass clazz(env->GetObjectClass(activity));
	jmethodID method_id = env->GetMethodID(clazz, "coreRewardedAdDidFinish", "()Z");

	jboolean videoHasFinishedPlaying = env->CallBooleanMethod(activity, method_id);

	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);

	return videoHasFinishedPlaying;
}

std::string coreGetRewardType()
{
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();

	jclass clazz(env->GetObjectClass(activity));
	jmethodID method_id = env->GetMethodID(clazz, "coreGetRewardType",  "()Ljava/lang/String;");

	jstring rewardType = (jstring) env->CallObjectMethod(activity, method_id);
	
	const char *strPtr = env->GetStringUTFChars(rewardType, 0);
	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);

	return (std::string) strPtr;
}

double coreGetRewardQuantity()
{
	JNIEnv *env = (JNIEnv*) SDL_AndroidGetJNIEnv();

	jobject activity = (jobject) SDL_AndroidGetActivity();

	jclass clazz(env->GetObjectClass(activity));
	jmethodID method_id = env->GetMethodID(clazz, "coreGetRewardQuantity",  "()D");

	jdouble rewardQty = (jdouble) env->CallDoubleMethod(activity, method_id);

	env->DeleteLocalRef(activity);
	env->DeleteLocalRef(clazz);

	return static_cast<double>(rewardQty);
}

} // android
} // love

#endif // LOVE_ANDROID
