
#include <iostream>
using namespace std;

//
// Scope Class Definition
//
class ScopeClass {
    
public:
    //
    // Class Constructors
    //
    
    // default constructor
    ScopeClass() : Cvar( DEFAULTCVAL )  {
        cout << "ScopeClass()" << endl;
        anotherInstance();
        var = 0;
    }
    
    // constructor that takes in specified values which are used
    // to initialize the data members
    ScopeClass(int v, int cv) : Cvar( cv ) {
        cout << "ScopeClass(" << v << ", " << cv << ")" << endl;
        anotherInstance();
        var = v;
    }
    
    //
    // Accessor methods
    //
    static int getInstance() {
        return( numOfInstances );
    }
    
    int getVar() const {
        return( var );
    }
    
    int getCVar() const {
        return( Cvar );
    }
    
    int getDEFAULTCVAL() const {
        return( DEFAULTCVAL );
    }
    
    //
    // Mutator methods
    //
    void setVar( int var ) {
        
        // use the scope resolution operator to resolve
        // scope issue as the identifier used in the
        // function parameter is the same as the name
        // of the data member.
        ScopeClass::var = var;
    }
    
    //
    // Class level input/output Prototypes
    //
    void input();
    void display() const;
    
    
private:
    // Class data members
    static const int DEFAULTCVAL = -1; // Class level default value to initialize constant variable Cvar
    static int numOfInstances; // Example data member of a class level static integer variable
    const int Cvar; // Example data member of a constant integer variable
    int var; // Example data member of a local integer variable
    
    //
    // Private class methods
    //
    
    //
    // method to increment the static variable
    // numOfInstances
    //
    void anotherInstance() {
        numOfInstances++;
    }
    
};
/*
 *
 * scopeClass.cpp
 *
 * This file contains the implentation of all the
 * methods of the class ScopeClass.
 *
 * Summer 2015
 *
 * Christine Papadakis
 *
 */

                                                                    
                                                                    //
                                                                    // Initialize the class static members in global space
                                                                    //
                                                                    int ScopeClass::numOfInstances;
                                                                    
                                                                    //
                                                                    // Method Implementations
                                                                    //
                                                                    
                                                                    //
                                                                    // input method to perform user input
                                                                    //
                                                                    void ScopeClass::input() {
                                                                    
                                                                    cout << "Enter integer variable: ";
                                                                    
                                                                    cin >> var;
                                                                    }
                                                                    
                                                
void ScopeClass::display() const {
    cout << "var == " << var << " cVar == " << Cvar << " numOfInstances == " << numOfInstances << endl;
}


int main() {
    cout << "Before Instantiation, Number of Instances == " << ScopeClass::getInstance() << endl;
    
    //
    // Create an instance of Scope Class
    // using the default constructor
    //
    
    cout << "Creating object using default constrcutor:\n";
    ScopeClass s;
    cout << "Number of Instances == " << s.getInstance()
    << " Var == " << s.getVar()
    << " Constant Variable == " << s.getCVar()
    << " Constant Static Variable == " << s.getDEFAULTCVAL() << endl;
    
    //
    // Create several more instances of Scope Class
    // using the specified constructor
    //
    cout << "Creating object using default constrcutor(1,5):\n";
    ScopeClass s1(1, 5);
    cout << "Number of Instances == " << s1.getInstance()
    << " Var == " << s1.getVar()
    << " Constant Variable == " << s1.getCVar()
    << " Constant Static Variable == " << s.getDEFAULTCVAL() << endl;
    
    cout << "Creating object using default constrcutor(2,10):\n";
    ScopeClass s2(2, 10);
    cout << "Number of Instances == " << s2.getInstance()
    << " Var == " << s2.getVar()
    << " Constant Variable == " << s2.getCVar()
    << " Constant Static Variable == " << s.getDEFAULTCVAL() << endl;
    
    cout << "Creating object using default constrcutor(12,6):\n";
    ScopeClass s3(12, 6);
    cout << "Number of Instances == " << s3.getInstance()
    << " Var == " << s3.getVar()
    << " Constant Variable == " << s3.getCVar()
    << " Constant Static Variable == " << s.getDEFAULTCVAL() << endl;
    
    cout << "After all objects are created, number of Instances == " << ScopeClass::getInstance() << endl;
    
    //
    // Create an array of Scope Class objects
    //
    // Note: How is the array of objects created?
    //
    cout << endl << "Creating an array of 10 objects:\n";
    const int MAX = 10;
    ScopeClass sArr[MAX];
    
    cout << endl << "Display the contents of all objects in the array:\n";
    for ( int i = 0; i < MAX; i++ ) {
        sArr[i].display();
    }
    
    cout << endl << "Set the value of var to the objects relative position in the array:\n";
    for ( int i = 0; i < MAX; i++ )
        sArr[i].setVar( i+1 );
    
    cout << endl << "Display the current contents of all objects in the array:\n";
    for ( int i = 0; i < MAX; i++ )
        sArr[i].display();
    
    cout << "At the end of the program, number of Instances == " << ScopeClass::getInstance() << endl;
}
