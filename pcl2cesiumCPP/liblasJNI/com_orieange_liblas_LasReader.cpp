#include "jni.h"
#include "com_orieange_liblas_LasReader.h"
#include "JniHelper.h"
#include "liblas\liblas.hpp"
#include <iostream>

/*
	 * Class:     com_orieange_liblas_LasReader
	 * Method:    read
	 * Signature: (Ljava/lang/String;)Ljava/util/ArrayList;
	 */
JNIEXPORT jobject JNICALL Java_com_orieange_liblas_LasReader_read
(JNIEnv * env, jclass, jstring jfilename)
{

	char* filename = JniHelper::jstringToChar(env, jfilename);

	std::cout << "File Name:" << filename << std::endl;

	std::ifstream ifs;
	ifs.open(filename, std::ios::in | std::ios::binary);

	if (!ifs.is_open())
	{
		std::cout << "This app can not open this las file!" << std::endl;
		return NULL;
	}

	std::cout << "This file is opened!" << std::endl;

	liblas::ReaderFactory readerFactory;
	liblas::Reader reader = readerFactory.CreateWithStream(ifs);

	jclass listClazz = env->FindClass("Ljava/util/ArrayList;");//获得ArrayList类引用
	jmethodID listCostruct = env->GetMethodID(listClazz, "<init>", "()V"); //获得得构造函数Id
	jobject listObj = env->NewObject(listClazz, listCostruct); //创建一个Arraylist集合对象
	jmethodID listAdd = env->GetMethodID(listClazz, "add", "(Ljava/lang/Object;)Z");
	jclass pointClazz = env->FindClass("Lcom/orieange/liblas/LasPoint;");//获得LasPoint类引用
	jmethodID pointConstruct = env->GetMethodID(pointClazz, "<init>", "()V"); //获得得构造函数Id

	std::cout << "This app read las start..." << std::endl;


	//liblas::Header const& header = reader.GetHeader();
	//liblas::SpatialReference srs = header.GetSRS();
	//std::string wkt = srs.GetWKT();


	while (reader.ReadNextPoint())
	{
		jdouble x = reader.GetPoint().GetX();
		jdouble y = reader.GetPoint().GetY();
		jdouble z = reader.GetPoint().GetZ();

		liblas::Color color = reader.GetPoint().GetColor();
		jint r = color.GetRed();
		jint g = color.GetGreen();
		jint b = color.GetBlue();

		jobject pointObj = env->NewObject(pointClazz, pointConstruct); //构造一个对象

		jfieldID point_x = env->GetFieldID(pointClazz, "x", "D");
		jfieldID point_y = env->GetFieldID(pointClazz, "y", "D");
		jfieldID point_z = env->GetFieldID(pointClazz, "z", "D");

		jfieldID point_r = env->GetFieldID(pointClazz, "r", "I");
		jfieldID point_g = env->GetFieldID(pointClazz, "g", "I");
		jfieldID point_b = env->GetFieldID(pointClazz, "b", "I");

		env->SetDoubleField(pointObj, point_x, x);
		env->SetDoubleField(pointObj, point_y, y);
		env->SetDoubleField(pointObj, point_z, z);

		env->SetIntField(pointObj, point_r, r);
		env->SetIntField(pointObj, point_g, g);
		env->SetIntField(pointObj, point_b, b);

		env->CallBooleanMethod(listObj, listAdd, pointObj);
	}
	std::cout << "This app read las end..." << std::endl;

	// 关闭文件流
	ifs.close();

	return listObj;

}