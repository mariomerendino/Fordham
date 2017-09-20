#include <iostream>
using namespace std;

int main()
{
    int x, y, z(0);
    
    cout << "Enter two integer values: ";
    cin >> x >> y;
    
    if ( x > y )
        z = x - y;
    
    if ( x < y )
        z = x - y;
    
    if ( x == y )
        z = x + y;
    
    cout << "The value of z is: ";
    cout << z;
}
