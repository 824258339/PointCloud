/*
 * Cesium Point Cloud Generator
 * 
 * Copyright 2017 - 2018
 * Chair of Geoinformatics
 * Technical University of Munich, Germany
 * https://www.gis.bgu.tum.de/
 * 
 * The Cesium Point Cloud Generator is developed at Chair of Geoinformatics,
 * Technical University of Munich, Germany.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 *     
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package cn.graceearth.pcl2cesium;

import cn.graceearth.pcl2cesium.gui.LASMainGui;

public class LASMain {

	public static void main(String[] args) throws Exception {		
		new LASMain().startUp(args);
	}
	
	// set look and feel
	static {
		try {
			
			javax.swing.UIManager.setLookAndFeel(javax.swing.UIManager.getSystemLookAndFeelClassName());
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void startUp(String[] args) {
		
		LASMainGui mainView = new LASMainGui();
		mainView.initGui();
		
		//Logger.info("初始化动态链接库开始...");
		
//		System.loadLibrary("/plugins/JniUtils");
//		Logger.info("初始化 JniUtils.dll");
//		System.loadLibrary("/plugins/liblas");
//		Logger.info("初始化 liblas.dll");
//		System.loadLibrary("/plugins/liblasJNI");
//		Logger.info("初始化 liblasJNI.dll");
		
		//Logger.info("初始化动态链接库完毕！");
	}
}
