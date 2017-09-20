#ifndef POLYGON_H
#define POLYGON_H

#include <iostream>
using namespace std;

class Polygon {
public:
	Polygon();
	Polygon(int, int, int, int, int, int);
	Polygon (int, int);
	void input();
	void inputlength();
	void inputwidth();
	void display();
	void displayPolygon();
	static int getnumberpoly();
	static int getmaxpolygons();
	int getlength();
	bool setwidth(int);
	bool setlength(int);
	int getwidth();
	void setperimeter(int);
	int getperimeter();
	void setarea(int);
	int getarea();
	void avgPer(int);
	void avgArea(int);
	int getavgarea();
	int getavgper();
	int getMAX() const;
	int getMIN() const;
	static void avgArea();
	static void avgPer();
	int calcarea();
	int calcPerim();
	

private: 
	static int numPolygons, tperimeter, tarea, avgarea, avgper;
	int length, width, perimeter, area;
	static const int  max_polygons = 25;
	static const int default_MAX= 10;
	static const int default_MIN = 100;
	const int MAX, MIN;
};
#endif

