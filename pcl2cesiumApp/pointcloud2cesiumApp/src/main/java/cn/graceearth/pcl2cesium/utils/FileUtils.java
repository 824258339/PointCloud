package cn.graceearth.pcl2cesium.utils;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class FileUtils {

	public static String getFileName(String filePath) {

		Pattern p = Pattern.compile(".las");
		Matcher m = p.matcher(filePath); //

		String suf = "";
		while (m.find()) {
			suf = filePath.substring(0, m.start());
			break;
		}

		if (!suf.isEmpty()) {

			String[] arr = suf.split("\\\\");
			return arr[arr.length - 1];
		}
		return suf;

	}

//	public static void main(String[] args) {
//
//		System.out.println(getFileName("E:\\3D\\激光点云\\LAS\\a.las"));
//
//	}

}
