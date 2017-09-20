/*CaveAdventure.cpp
 * Author: Kristoffer Buenaventura
 * Class: Computer Science II
 * Professor: Professor Papadakis
 * Purpose: Creation of an awesome cave adventure game!
 * Last Modified: 14 September 2015 */

#include <iostream>
#include <cstdlib> //For srand() and rand(), used for RNG
#include <ctime> //For time(), used for RNG
#include <stdlib.h> // For exit()
#include <string.h>
#include <stdio.h>//For memcpy()

using namespace std;

void TwelveDays()//Prints out the Twelve Days of Christmas
{
    string days[12] = {"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"};
    
    string gifts[12] = {" a partridge in a pear tree!",
        " Two turtle doves, and",
        " Three french hens,",
        " Four calling birds,",
        " Five golden rings,",
        " Six geese-a-laying,",
        " Seven swans-a-swimming,",
        " Eight maids-a-milking,",
        " Nine ladies dancing,",
        " Ten lords a-leaping,",
        " Eleven pipers piping,",
        " Twelve drummers drumming,"};
    
    
    for (int x = 0; x < 12 ; x++)
    {
        
        switch (x)
        {
            case 0: cout << "\nOn the " << days[x] << " day of Christmas, my true love gave to me," << endl;
                cout << gifts[x] << endl;
                break;
            case 1: cout << "\nOn the " << days[x] << " day of Christmas, my true love gave to me," << endl;
                for (int x=1;x>=0;x--)
                {
                    cout << gifts[x] << endl;
                }
                break;
            case 2: cout << "\nOn the " << days[x] << " day of Christmas, my true love gave to me," << endl;
                for (int x=2;x>=0;x--)
                {
                    cout << gifts[x] << endl;
                }
                break;
            case 3: cout << "\nOn the " << days[x] << " day of Christmas, my true love gave to me," << endl;
                for (int x=3;x>=0;x--)
                {
                    cout << gifts[x] << endl;
                }
                break;
            case 4: cout << "\nOn the " << days[x] << " day of Christmas, my true love gave to me," << endl;
                for (int x=4;x>=0;x--)
                {
                    cout << gifts[x] << endl;
                }
                break;
            case 5: cout << "\nOn the " << days[x] << " day of Christmas, my true love gave to me," << endl;
                for (int x=5;x>=0;x--)
                {
                    cout << gifts[x] << endl;
                }
                break;
            case 6: cout << "\nOn the " << days[x] << " day of Christmas, my true love gave to me," << endl;
                for (int x=6;x>=0;x--)
                {
                    cout << gifts[x] << endl;
                }
                break;
            case 7: cout << "\nOn the " << days[x] << " day of Christmas, my true love gave to me," << endl;
                for (int x=7;x>=0;x--)
                {
                    cout << gifts[x] << endl;
                }
                break;
            case 8: cout << "\nOn the " << days[x] << " day of Christmas, my true love gave to me," << endl;
                for (int x=8;x>=0;x--)
                {
                    cout << gifts[x] << endl;
                }
                break;
            case 9: cout << "\nOn the " << days[x] << " day of Christmas, my true love gave to me," << endl;
                for (int x=9;x>=0;x--)
                {
                    cout << gifts[x] << endl;
                }
                break;
            case 10: cout << "\nOn the " << days[x] << " day of Christmas, my true love gave to me," << endl;
                for (int x=10;x>=0;x--)
                {
                    cout << gifts[x] << endl;
                }
                break;
            case 11: cout << "\nOn the " << days[x] << " day of Christmas, my true love gave to me," << endl;
                for (int x=11;x>=0;x--)
                {
                    cout << gifts[x] << endl;
                }
                break;
        }
    }
}

void proceed()//Tests user bravery (to continue or not to continue)
{
    char proceed;
    cin >> proceed;
    
    if (proceed == 'N' || proceed == 'n')
    {
        cout << "Coward!";
        exit(0);//Exits function completely.
    }
    
}

void OldMacDonald()//Recites the OldMacDonald song
{
    srand(time(0));
    //Different orders of animals
    string animalOne[4] = {"cow", "sheep", "pig", "chicken"};
    string animalTwo[4] = {"sheep", "cow", "chicken", "pig"};
    string animalThree[4] = {"chicken", "pig", "cow", "sheep"};
    string animalFour[4] = {"pig", "sheep", "chicken", "cow"};
    
    string animalRandom[4];//This array will take the value of any of the previous 4
    
    string soundOne[4] = {"moo", "baa", "oink", "cluck"};
    string soundTwo[4] = {"baa", "moo", "cluck", "oink"};
    string soundThree[4] = {"cluck", "oink", "moo", "baa"};
    string soundFour[4] = {"oink", "baa", "cluck", "moo"};
    
    string soundRandom[4];//Same thing for this array
    
    int randomizer = (rand() % 4);//Randomizer variable (different order each time the function is called)
    
    switch(randomizer)
    {
        case 0: memcpy(animalRandom, animalOne, sizeof(animalOne));//Using memcpy() to transfer values from one array to another
            memcpy(soundRandom, soundOne, sizeof(soundOne));
            break;
            
        case 1: memcpy(animalRandom, animalTwo, sizeof(animalTwo));
            memcpy(soundRandom, soundTwo, sizeof(soundTwo));
            break;
            
        case 2: memcpy(animalRandom, animalThree, sizeof(animalThree));
            memcpy(soundRandom, soundThree, sizeof(soundThree));
            break;
            
        case 3: memcpy(animalRandom, animalFour, sizeof(animalFour));
            memcpy(soundRandom, soundFour, sizeof(soundFour));
            break;
    }
    
    for (int x = 0; x<4; x++)
    {
        cout << "\n\nOld McDonald had a farm, E-I-E-I-O!" << endl;
        
        cout << "And on that farm there was a " << animalRandom[x] << ", E-I-E-I-O!" << endl;
        
        cout << "With a " << soundRandom[x] << "-" << soundRandom[x] << " here and a " << soundRandom[x] << "-" << soundRandom[x] << " there," << endl;
        
        cout << "here a " << soundRandom[x] << " there a " << soundRandom[x] << " everywhere a " << soundRandom[x] << "-" << soundRandom[x] << "!";
    }
    
    cout << "\n\nOld McDonald had a farm, E-I-E-I-O!" << endl;
    
}

void Truffle()//Function for first access way
{
    char decision1;
    cin >> decision1;
    
    if (decision1 == '1')
    {
        cout << "\nYou have slayed the infamous Truffle King! However, you were armed with only a fork and spoon!" << endl;
        cout << "You have been gravely injured! What would you like to do now?" << endl << endl;
        
        cout << "\t1) Journey deeper towards the Crystalline Cavern!" << endl;
        cout << "\t2) Arm myself with the treasured Swiffer Wet Jet!" << endl;
        
        char decision2;
        cin >> decision2;
        
        if (decision2 == '1')
        {
            cout << "You attempt to move forward, but are killed by huge clouds of hostile dust!" << endl;
            cout << "If only you had a cleaing tool of great efficiency! GAME OVER!" << endl;
            
            exit(0);
        }
        
        else if (decision2 == '2')
        {
            cout << "Great! You can now move forward!" << endl;
            return; //Goes back to main function.
        }
    }
    
    else if (decision1 == '2')
    {
        cout << "\nChecking the cleaning closet, you arm yourself with cleaning power of an unparalled degree!" << endl;
        cout << "You are suddenly overcome with exhaustion and fall into a deep sleep!" << endl;
        
        OldMacDonald();
        
        cout << "\nYou awaken well-rested, carrying the scent of various farm animals in your breath!" << endl;
        cout << "With your newfound strength and amazing cleaning tool, you slay the Truffle King with little to no effort!" << endl;
    }
}

void Crystal()//Function for second access way.
{
    char decision1;
    cin >> decision1;
    
    if (decision1 == '1')
    {
        cout << "\nAfter a grueling four week battle, you slay the 100-Legged Alpaca! However, you were in your boxers the whole time!" << endl;
        cout << "You have been greatly embarassed! What would you like to do now?" << endl << endl;
        
        cout << "\t1) Journey deeper towards the Planet Core!" << endl;
        cout << "\t2) Don the mighty Golden Snuggie!" << endl;
        
        char decision2;
        cin >> decision2;
        
        if (decision2 == '1')
        {
            cout << "You attempt to move forward, but your high school principal appears and berates you for violating dress code!" << endl;
            cout << "If only you did not choose the life of a streaker! GAME OVER!" << endl;
            
            exit(0);
        }
        
        else if (decision2 == '2')
        {
            cout << "Great! You can now move forward!" << endl;
            return; //Goes back to main function.
        }
        
        else if (decision1 == '2')
        {
            cout << "\nYou find the Golden Snuggie underneath the arm of a giant troll!" << endl;
            cout << "With great care, you sneakily pry the amazingly comfortable cloak from its grasp and put it on!" << endl;
            cout << "You are suddenly overcome with exhaustion and fall into a deep sleep!" << endl;
            
            OldMacDonald();
            
            cout << "\nOnce again, you wake up feeling refreshed, but your Golden Snuggie now reeks of bacon, steak, and eggs!" << endl;
            cout << "However, before you are able to slay the 100-Legged Alpaca, eerie whispers begin to fill the cavern..." << endl;
            
            cout << "Your head is filled with whispers of the fabled iPhone, a legendary device that will surely skip you to the end of the game!" << endl;
            cout << "Would you like to search the Crystalline Cavern for the iPhone, or continue and slay the 100-Legged Alpaca?" << endl << endl;
            
            cout << "\t1) I can't resist such convenience and power! Search for the iPhone!" << endl;
            cout << "\t2) I'm okay with my Sony Walkman. Slay the 100-Legged Alpaca!" << endl;
            
            char decision3;
            cin >> decision3;
            
            if (decision3 == '1')
            {
                cout << "\nStrange laughter fills the air, and you are swarmed by thousands upon thousands of Christmas elves!" << endl;
                
                TwelveDays();
                
                cout << "\nUnable to keep all the gifts, you apologize and move past the wailing, disappointed elves!" << endl;
                cout << "Finally, you are able to slay the 100-Legged Alpaca! It is time to move on." << endl;
            }
            
            else if (decision3 == '2')
            {
                cout << "Satisfied with your outdated technology, you move on and slay the 100-Legged Alpaca!" << endl;
                cout << "You are finally able to move on!" << endl;
            }
        }
    }
    
    int main ()
    {
        char repeat; //Allows user to start over!
        
        do {
            
            cout << "\n\n\t\t******You have entered Kristoffer Buenaventura's Cave Adventure program...BEWAREEEEE*********" << endl << endl;
            
            cout << "Brave warrior! Honor me with knowledge of your name: " << endl;
            
            string name;
            
            cin >> name;
            
            cout << "\nWe are in dire need of your help, " << name << "!" << endl;
            cout << "The foul goblins of the Northern Caves have been a thorn in our side for too long!" << endl;
            cout << "What say you we rid the world of these blighted creatures? (Y/N) " << endl;
            
            proceed();
            
            cout << "Great! Are you ready to begin your adventure and enter the daunting Truffle Mountains? (Y/N)" << endl;
            
            proceed ();
            
            cout << "\nYou have entered the Truffle Mountains without incident. What would you like to do now?" << endl << endl;
            
            cout << "\t1) Slay the Truffle King!" << endl;
            cout << "\t2) Arm myself with the treasured Swiffer Wet Jet!" << endl;
            
            Truffle();
            
            cout << "Well done brave warrior! Are you now ready to venture into the Crystalline Cavern? (Y/N)" << endl;
            
            proceed ();
            
            cout << "Braving your way through the darkness, you finally make it to the Crystalline Cavern!" << endl;
            
            cout << "What would you like to do now?" << endl << endl;
            
            cout << "\t1) Slay the 100-Legged Alpaca!" << endl;
            cout << "\t2) Don the mighty Golden Snuggie!" << endl;
            
            Crystal();
            
            cout << "\n\nWould you like to start over?" << endl;
            cout << "Enter 'Y' if Yes, or 'N' if No." << endl;
            
            cin >> repeat;
            
        } while (repeat == 'Y' || repeat == 'y');
        
        cout << "Farewell warrior!" << endl;
        
        cout << "\nThis program was created by Kristoffer Buenaventura for Professor Papadakis." << endl;
        return 0;
    }