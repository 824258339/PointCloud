package com.orieange.liblas.sample;

public class LasReaderSample {
	public static void main(String[] args) {

		System.out.println("load libary begin...");
		System.loadLibrary("../../platform/plugins/pcl2cesium/JniUtils");
		System.loadLibrary("../../platform/plugins/pcl2cesium/liblas");
		System.loadLibrary("../../platform/plugins/pcl2cesium/liblasJNI");
		System.out.println("load libary end!");

		// ArrayList<LasPoint> points = LasReader.read("E:/3D/婵�鍏夌偣浜�/LAS/Autzen_Stadium/lidar.las");
		// ArrayList<LasPoint> points = LasReader.read("E:/3D/婵�鍏夌偣浜�/LAS/寤哄北鐢茬嚎1-5鍙峰.las");
		//ArrayList<LasPoint> points = LasReader.read("E:\\3D\\婵�鍏夌偣浜慭\LAS\\stadium_all\\stadium_all.las");
//		ArrayList<LasPoint> points = LasReader.read("E:\\3D\\婵�鍏夌偣浜慭\LAS\\鍩庡競璺潰.las");
//		
//		if (points == null || points.isEmpty()) {
//			return;
//		}
//
//		System.out.println(points.size());
//
//		for (LasPoint p : points) {
//			System.out.println(
//					p.getX() + ", " + p.getY() + ", " + p.getZ() + ", " + p.getR() + ", " + p.getG() + ", " + p.getB());
//		}

	}

}
