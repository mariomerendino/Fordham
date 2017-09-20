#include<iostream>
using namespace std;

int lcm(int x, int y){
    int max;
    if (x > y)
        max = x;
    else
        max = y;
    for (int i = max; i < x*y; i++){
        if (max % x == 0 && max % y == 0)
        {
            return max;
        }
    }
    
}

int main(){
    cout << "enter 2 numbers" << endl;
    int x, y;
    cin >> x;
    cin >> y;
    cout << lcm(x,y);
}