package com.orieange.liblas;

/**
 * LAS文件中的点
 * 
 * @author LYN
 *
 */
public class LasPoint {

	LasPoint() {

	}

	private double x;
	
	private double y;
	
	private double z;
	
	private int r;
	
	private int g;
	
	private int b;

	public double getX() {
		return x;
	}

	public void setX(double x) {
		this.x = x;
	}

	public double getY() {
		return y;
	}

	public void setY(double y) {
		this.y = y;
	}

	public double getZ() {
		return z;
	}

	public void setZ(double z) {
		this.z = z;
	}

	public int getR() {
		return r;
	}

	public void setR(int r) {
		this.r = r;
	}

	public int getG() {
		return g;
	}

	public void setG(int g) {
		this.g = g;
	}

	public int getB() {
		return b;
	}

	public void setB(int b) {
		this.b = b;
	}
	
	
	
}
