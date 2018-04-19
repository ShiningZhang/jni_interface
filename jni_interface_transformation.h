#include <jni.h>

#ifndef _INCLUDE_JNI_INTERFACE_TRANSFORMATION_
#define _INCLUDE_JNI_INTERFACE_TRANSFORMATION_

#include <android/log.h>

#define JNI_INTERFACE_TRANSFORMATION_CLOSE 0
#define JNI_INTERFACE_TRANSFORMATION_NOTIC 1
#define JNI_INTERFACE_TRANSFORMATION_WARNING 2
#define JNI_INTERFACE_TRANSFORMATION_ERROR 3

#define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, TAG, __VA_ARGS__)
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, TAG, __VA_ARGS__)
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN, TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, TAG, __VA_ARGS__)

#define LOG_LEVEL(LEVEL, ...) \
    do { \
        if (LEVEL == JNI_INTERFACE_TRANSFORMATION_NOTIC) \
            __android_log_print(ANDROID_LOG_INFO, TAG,__VA_ARGS__); \
        if (LEVEL == JNI_INTERFACE_TRANSFORMATION_WARNING) \
            __android_log_print(ANDROID_LOG_WARN, TAG,__VA_ARGS__); \
        if (LEVEL == JNI_INTERFACE_TRANSFORMATION_ERROR) \
            __android_log_print(ANDROID_LOG_ERROR, TAG,__VA_ARGS__); \
    } while(0)

const char* string2char(JNIEnv *env, jstring s);

JNIEXPORT jstring JNICALL char2string(JNIEnv *env, const char * s);

void releasestring(JNIEnv *env, jstring js, const char *s);

char* byteArray2char(JNIEnv *env, jbyteArray array);

void releaseByteArray(JNIEnv *env, jbyteArray array, char * array_c);

/**
e.g. clsName = "com/example/Main$NativeObject"
paramType = "()V" - void()  "()[I" - int[]()  "([Lcon/example/test;)V" - void(test[])
**/
jobject getClassObject(JNIEnv *env, const char * clsName, const char * paramType, ...);

void setField(JNIEnv *env, jclass cls, jobject jobt, const char * field, int i);

#endif