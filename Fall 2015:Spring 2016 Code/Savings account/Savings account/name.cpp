#include "name.h" 

Name::Name(){//Default Constructor
    fname = "Johnny"; 
    mi = 'A'; 
    lname = "AppleSeed"; 
}
Name::Name(string f, char m, string l){
    fname = f;
    mi = m;
    lname = l;
}

void Name::display(){ //Display function
    cout << "Name: " << getfname() << " " << getmi() << " " << getlname();
}
void Name::input(){ //input function
    cout << "Enter First name: ";
    cin >> fname;
    cout << "Enter Middle Initial: "; 
    cin >> mi;
    cout << "Enter Last name: "; 
    cin >> lname;
}
void Name::setfname(string f){ //Mutator for fname
    f = fname;
}
string Name::getfname(){//accessor for fname
   return(fname);
}
void Name::setlname(string l){//mutator for lname
    lname = l;
}
string Name::getlname(){//accessor for lame
   return(lname);
}
char Name::getmi(){//accessor for mi
   return(mi);
}
void Name::setmi(char m){//mutators for mi
    m=mi;
}
