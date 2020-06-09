package com.orieange.liblas;

import java.util.ArrayList;

/**
 * LAS 点云文件读取
 * 
 * @author LYN
 *
 */
public class LasReader {
	
	
	public native static ArrayList<LasPoint> read(String fileName);

}
