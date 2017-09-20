#include <iostream>
#include "polygon.h"

int Polygon::numPolygons = 0;
int Polygon::tarea = 0;
int Polygon::tperimeter = 0;
int Polygon::avgarea = 0;
int Polygon::avgper = 0;

//constructors
Polygon::Polygon():MIN(default_MIN), MAX(default_MAX) {

	length = 0;
	width = 0;
	perimeter = calcPerim();
	area = calcarea();
	numPolygons++;

}
Polygon::Polygon(int maxval, int minval, int w, int p, int l, int a):MAX(maxval), MIN(minval){
	
	l = length;
	w = width;
	perimeter = calcPerim();
	area = calcarea();
	numPolygons++;
}
Polygon::Polygon(int maxval, int minval):MAX(maxval),MIN(minval){
	length = 0;
	width = 0;
	perimeter = calcPerim();
	area = calcarea();
}
bool Polygon::setwidth(int w) {
	if (w>= MIN  && w <= MAX){
		width = w;
	}
}
bool Polygon::setlength(int l) {
	if (l>=MIN &&l <= MAX){
		length = l;
	}
}

//accessor methods
int Polygon::getwidth(){
	return(width);
}
int Polygon::getlength(){
	return(length);
}
int Polygon::getnumberpoly(){
	return(numPolygons);
}
int Polygon::getmaxpolygons(){
	return(max_polygons);
}
int Polygon::getperimeter(){
	return(perimeter);
}
int Polygon::getarea() {
	return(area);
}
int Polygon::getavgper(){
	return(avgper);
}
int Polygon::getavgarea(){
	return(avgarea);
}
int Polygon::calcarea() {
	area = (width*length);
	tarea = tarea + area;
	
	return(area);
}
int Polygon::calcPerim(){
	perimeter = ((width*2) + (length*2));
	tperimeter = tperimeter + perimeter;
	
	return (perimeter);
}

void Polygon::avgArea(){
	avgarea = tarea / numPolygons;
}

void Polygon::avgPer(){
	avgper = tperimeter / numPolygons;
}
void Polygon::display(){
	cout << "Length: " << getlength() <<  endl;
	cout << "Width: " << getwidth() <<  endl;
	cout << "Area: " << getarea()  << endl;
	cout << "Perimeter: " << getperimeter() << endl;
	cout << "Average Area: " << getavgarea() << endl;
	cout << "Average Perimeter: " << getavgper() << endl;
}

void Polygon::displayPolygon(){

for(int i=0; i<=length; i++){
	for (int j=0; j<= width; j++){
		if(j == 0 || i == length || j == 0 || j == width){
			cout << "*";
		}
		else{
			cout << endl;
		}
	}
}
}
void Polygon::inputlength(){
	int l;
	do{
	cout << "input the length of the desired polygon" << endl;
	cin >> l;
	}while(!setlength(l));
}
	


void  Polygon::inputwidth(){
	int w;
	do{
	cout << "Enter the width of the desired polygon" << endl;
	cin >> w;
	}while(!setwidth(w));
}

void Polygon::input(){
cout << "Enter the length of the polygon: " << endl;
cin >> length;
cout << "enter the width  of the polygon: " << endl;
cin >> width;
//inputlength();
//inputwidth();
calcPerim();
calcarea();
avgPer();
avgArea();

}



