#include "JniHelper.h"
#include "string.h"
#include<stdio.h>


JniHelper::JniHelper()
{
}


JniHelper::~JniHelper()
{
}

jstring JniHelper::charTojstring(JNIEnv* env, const char* pat)
{
	//定义java String类 strClass
	jclass strClass = (env)->FindClass("Ljava/lang/String;");
	//获取String(byte[],String)的构造器,用于将本地byte[]数组转换为一个新String
	jmethodID ctorID = (env)->GetMethodID(strClass, "<init>", "([BLjava/lang/String;)V");
	//建立byte数组
	jbyteArray bytes = (env)->NewByteArray(strlen(pat));
	//将char* 转换为byte数组
	(env)->SetByteArrayRegion(bytes, 0, strlen(pat), (jbyte*)pat);
	// 设置String, 保存语言类型,用于byte数组转换至String时的参数
	jstring encoding = (env)->NewStringUTF("GB2312");
	//将byte数组转换为java String,并输出
	return (jstring)(env)->NewObject(strClass, ctorID, bytes, encoding);
}

char* JniHelper::jstringToChar(JNIEnv *env, jstring jstr)
{

	int length = (env)->GetStringLength(jstr);
	const jchar* jcstr = (env)->GetStringChars(jstr, 0);
	char* rtn = (char*)malloc(length * 2 + 1);
	int size = 0;
	size = WideCharToMultiByte(CP_ACP, 0, (LPCWSTR)jcstr, length, rtn,
		(length * 2 + 1), NULL, NULL);
	if (size <= 0)
		return NULL;
	(env)->ReleaseStringChars(jstr, jcstr);
	rtn[size] = 0;
	return rtn;

}

jstring JniHelper::string2jstring(JNIEnv *env, std::string str)
{
	const char* chardata = str.c_str();
	// char* 转 string
	jstring jstr = charTojstring(env, chardata);

	return jstr;
}

std::string JniHelper::jstring2string(JNIEnv *env, jstring jstr)
{
	char* chardata = jstringToChar(env, jstr);
	// char* 转 string
	std::string str = chardata;
	return str;
}
