#include <iostream>
using namespace std;
int b = 1;
int x() {b++; return b;}
int y() {b*=3; return b-1;}
int z() {b=b+8; return b+2;}

int main( ) {
    int a = x() - y() + z();
    cout << a;
}
