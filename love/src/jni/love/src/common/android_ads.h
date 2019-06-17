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

#ifndef LOVE_ANDROID_ADS_H
#define LOVE_ANDROID_ADS_H

#include "config.h"

#ifdef LOVE_ANDROID

#include <string>

namespace love
{
namespace android
{

//Ads
void createBanner(const char *adID,const char *position);
	
void hideBanner();
	
void showBanner();

void requestInterstitial(const char *adID);

bool isInterstitialLoaded();

void showInterstitial();

void requestRewardedAd(const char *adID);

bool isRewardedAdLoaded();

void showRewardedAd();

//For callbacks
bool coreInterstitialError();

bool coreInterstitialClosed();

bool coreRewardedAdError();

bool coreRewardedAdDidStop();

bool coreRewardedAdDidFinish();

std::string coreGetRewardType();

double coreGetRewardQuantity();

} // android
} // love

#endif // LOVE_ANDROID
#endif // LOVE_ANDROID_ADS_H
