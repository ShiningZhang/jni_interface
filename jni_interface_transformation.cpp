#include "jni_interface_transformation.h"

const char* string2char(JNIEnv *env, jstring s)
{
    return env->GetStringUTFChars(s, 0);
}

jstring char2string(JNIEnv *env, const char * s)
{
    return env->NewStringUTF(s);
}

void releasestring(JNIEnv *env, jstring js, const char *s)
{
    env->ReleaseStringUTFChars(js, s);
}

char* byteArray2char(JNIEnv *env, jbyteArray array)
{
    return (char*)env->GetByteArrayElements(array, 0);
}

void releaseByteArray(JNIEnv *env, jbyteArray array, char * array_c)
{
    env->ReleaseByteArrayElements(array, (jbyte *)array_c, 1);
}


jobject getClassObject(JNIEnv *env, const char * clsName, const char * paramType, ...)
{
    jclass cls;
    jmethodID constructor;
    jobject jobt;
    va_list args;

    if((cls = env->FindClass(clsName)) == 0)
    {
        return 0;
    }
    if((constructor = env->GetMethodID(cls, "<init>", paramType)) == 0)
    {
        return 0;
    }

    va_start(args, paramType);

    if((jobt = env->NewObjectV(cls, constructor, args)) == 0)

    va_end(args);

    return jobt;
}

void setField(JNIEnv *env, jclass cls, jobject jobt, const char * field, int i)
{
    jfieldID fieldID = env->GetFieldID(cls, field, "I");
    env->SetIntField(jobt, fieldID, i);
}