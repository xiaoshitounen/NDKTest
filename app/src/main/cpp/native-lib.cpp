#include <jni.h>
#include <string>
#include "Test.h"

extern "C" JNIEXPORT jstring JNICALL
Java_swu_xl_baidu_ndktest_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_swu_xl_baidu_ndktest_MainActivity_getTestString(JNIEnv *env, jobject thiz, jstring str) {

    const char *xl_str = (env->GetStringUTFChars(str, 0));

    Test* test = new Test;
    std::string result = test->getTestString(xl_str);

    return env->NewStringUTF(result.c_str());
}