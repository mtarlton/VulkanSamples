// From http://www.50ply.com/blog/2013/01/19/loading-compressed-android-assets-with-file-pointer/

#ifndef ANDROID_FOPEN_H
#define ANDROID_FOPEN_H

#include <android/asset_manager.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

/* hijack fopen and route it through the android asset system so that
   we can pull things out of our package's APK */

void android_fopen_set_asset_manager(AAssetManager *manager);
FILE *android_fopen(const char *fname, const char *mode);

#define fopen(name, mode) android_fopen(name, mode)

#ifdef __cplusplus
}
#endif

#endif
