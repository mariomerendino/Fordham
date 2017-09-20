//
//  main.cpp
//  Package Lab
//
//  Created by Mario J Merendino on 12/7/15.
//  Copyright (c) 2015 Mario J Merendino. All rights reserved.
//

#include "Package.h"
#include "Twoday.h"
#include "Overnight.h"
int main() {
    int counterX(0), counterY(0);//counters for twoday and overnight packagees
    int choice;
    bool exit(false);
    twoday *x[100];//creates 100 twoday pointers
    overnight *y[100];//creates 100 overnight pointers
    cout << "Welcome to UPS Expedited shipping! Enter up to 100 packages"<<endl;
    for(int i=0; i<100; i++){//loops through 100 times
        while (!exit){
            cout << "How Would you like to ship your package?\n\t1.Twoday\n\t2.Overnight\n\t3.Exit\n>>";
            cin >> choice;//user choses what service
            switch(choice){
                case 1:
                    x[counterX]=new twoday();//creates a twoday package
                    x[counterX]->input();//input weight
                    counterX++;//counter increases
                    break;
                case 2:
                    y[counterY]=new overnight();//creates new overnight package
                    y[counterY]->input();//input weight
                    counterY++;//counter increases
                    break;
                case 3:
                    exit=true;//if user choses this input ends
                    break;
                default://default case
                    exit=true;
                    break;
            }
        }
    }
    cout <<"Two Day Packages: " <<endl;
    for (int i=0; i<counterX; i++){ //displays all twoday packages
        int num=i+1;
        cout << "Pacakge " << num <<endl;
        x[i]->display();
        cout << endl;
    }
    cout << "\nOvernight Packages: " << endl;
    for (int i=0; i<counterY; i++){//displays all overnight
        int num=i+1;
        cout << "Pacakge " << num <<endl;
        y[i]->display();
        cout << endl;
    }
    x[counterX]->stats();//stats for all twoday
    y[counterY]->stats();//stats for all overnight
}
