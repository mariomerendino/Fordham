
#include <iostream> 
#include <string.h>
using namespace std;

class undergraduate{
    
public:
    undergraduate(string f, string l, int m, int, int d, int y){
        f=fname;
        l=lname;
        m=mm;
        d=dd;
        y=yy;
    }
    
private:
    int mm,dd,yy;
    string fname, lname;
    char mi, status;
};

int main(){
    undergraduate u1;
    undergraduate u1("Mark", "Ward", 01, 20, 1996);
    cout << u1.undergraduate;
}
