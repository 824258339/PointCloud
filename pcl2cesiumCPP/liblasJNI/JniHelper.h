
#pragma once

#include "stdafx.h"
#include "jni.h"
#include <iostream>

class __declspec(dllexport) JniHelper
{
public:
	JniHelper();
	~JniHelper();

	static jstring charTojstring(JNIEnv* env, const char* pat);

	static char* jstringToChar(JNIEnv *env, jstring jstr);

	static jstring string2jstring(JNIEnv *env, std::string jstr);

	static std::string jstring2string(JNIEnv *env, jstring jstr);
};

