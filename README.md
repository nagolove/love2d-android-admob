Android Port of LÖVE, the awesome 2D game engine LÖVE (http://love2d.org)

This repository is a fork of the projects:
* https://bitbucket.org/rude/love/
* https://bitbucket.org/bio1712/love2d-admob-android/
* https://bitbucket.org/MartinFelis/love-android-sdl2/

Admob instruction - https://love2d.org/forums/viewtopic.php?f=5&t=84226

Quick Start:
------------

Install the Android NDK and the Android SDK with SDK API 28, set the
environment variables ```ANDROID_NDK```, ```ANDROID_SDK```and
```ANDROID_HOME```, create a file ```local.properties``` with contents:

    ndk.dir=/opt/android-ndk
    sdk.dir=/opt/android-sdk

(you may have to adjust the paths to the install directories of the Android
SDK and Android NDK on your system) and run

    ./gradlew build

in the root folder of this project. This should give you a .apk file in the
app/build/outputs/apk/ subdirectory that you can then install on your phone.

Alternatively, you can install Android Studio. After opening it for the first time,
open it's SDK Manager and on the tab "SDK Tools", select NDK. After that, open the
repository root.

Put the game (game.love) in the directory (project)/app/src/main/assets (if this directory don't exist create it). 

License:
--------

This project contains code from multiple projects using various licenses.
Please look into the folders of love/src/jni/<projectname>/ for the respective
licenses. A possibly incomplete overview of dependent and included
libraries and licenses is the following:

* FreeType2 (FreeType Project License)
* libjpeg-turbo (custom license)
* libmodplug (public domain)
* libogg (BSD License)
* libvorbis (BSD License)
* LuaJIT (MIT License)
* mpg123 (LGPL 2.1 License)
* openal-soft (LGPL 2 License)
* physfs (zlib License)
* SDL2 (zlib License)

This project also includes LÖVE, which itself is licensed under the zlib
license but includes the following libraries that are subject to other
licenses:

* modified Box2D (original Box2D license is zlib)
* ddsparse (MIT License)
* enet (MIT License)
* glad (MIT License)
* lodepng (zlib License)
* luasocket (MIT License)
* SimplexNoise1234 (public domain)
* stb_image (public domain)
* utf8 (Boost License)
* wuff (public domain)

As for the other code, modifications to LÖVE, and build system files are
are published under the zlib license (same as LÖVE).
