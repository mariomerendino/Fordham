#include <iostream>
#include "polygon.h"

using namespace std;

int main (){
const int MAX = Polygon::getmaxpolygons();

int choice;

Polygon *p[MAX];
cout << "Welcome to my Program. Lets draw some polygons nigga" << endl;
cout << "How many polygons would you like to make?" << endl;
cin >> choice;
for (int x = 0; x < choice; x++){
	p[x] = new Polygon;
	p[x] -> display();
	p[x] -> input();
	p[x] -> display();
}
cout << "Polygons created: " << Polygon::getnumberpoly() << endl;

bool validate = false;
bool validate2 = false;
char ans;
int x;
do{
	cout << "Would you like to see any of the polygons you've created? (y/n)" << endl;
	cin >> ans;
		if (ans == 'Y' || ans == 'y'){
			do{
				cout << "Which polygon would you like to see?" << endl;
				cin >> x;
				if (x <= choice){
					p[x-1] -> displayPolygon();
					validate = true;
					validate2 = true;
				}
			}while(!validate);
		}
		else{
			cout << "Thanks for using my program" << endl;
			validate2 = true;
		}
	}while(!validate2);
	
	delete p[choice];
}


		
