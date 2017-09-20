//
//  main.cpp
//  Lab9
//
//  Created by Mario J Merendino on 5/7/15.
//  Copyright (c) 2015 M

#include <iostream>
using namespace std;

const char SPACE = ' ';
int winnerIs(char a, char b, char c)
{
    if (a == b && b == c)
        switch(a)
    {
        case 'O':
            return 1;
        case 'X':
            return 2;
    }
    return -1;
}

int findWinner(char a[][3])
{
    int winner;
    for (int i=0; i<3; i++)
    {
        if ((winner = winnerIs(a[i][0], a[i][1],a[i][2])) > 0)
            return winner;
        if ((winner = winnerIs(a[0][i], a[1][i],a[2][i])) > 0)
            return winner;
    }
    if ((winner = winnerIs(a[0][0], a[1][1],a[2][2])) > 0)
        return winner;
    if ((winner = winnerIs(a[0][2], a[1][1],a[2][0])) > 0)
        return winner;
return -1;
}

void display(const char a[][3])
{
    cout << "+--+--+--+" << endl;
    cout << "+" << a[0][0] << " |" << a[0][1] << " |" << a[0][2] << " +" << endl;
    cout << "+--+--+--+" << endl;
    cout << "+" << a[1][0] << " |" << a[1][1] << " |" << a[1][2] << " +" << endl;
    cout << "+--+--+--+" << endl;
    cout << "+" << a[2][0] << " |" << a[2][1] << " |" << a[2][2] << " +" << endl;
    cout << "+--+--+--+" << endl;
    
    cout << endl;
}

bool positionEntered(char a[][3], int player)
{
    int row, col;
    char piece;
    if (++player == 1)
        piece = 'O';
    else
        piece = 'X';
    
    cout << "Player " << player << " (with piece " << piece << "): \n";
    cout << "Enter the position to place your piece (row col): " ;
    cin  >> row >> col;
if ((row > 0 && row-- < 4) &&
    (col > 0 && col-- < 4))
{
    if (a[row][col] != SPACE)
    {
        cout << "Position is already TAKEN!!!!!!!!\n\n";
        return false;
        }
        a[row][col] = piece;
        return true;
        }
        cout << "INVALID position entered!!!!!!!!!\n" << endl;
        return false;
        }
        
        
        int main()
        {
            char a[3][3] = {SPACE, SPACE, SPACE,
                SPACE, SPACE, SPACE,
                SPACE, SPACE, SPACE};
            char moves = 0;
            int  winner;
            
            display(a);
            do
            {
                while (positionEntered(a,moves % 2) == false);
                display(a);
            } while ((winner = findWinner(a)) == -1 && ++moves < 9);
            
            
            if (winner > -1)
                cout << "The winner is player " << winner;
            else
                cout << "Tie.";
            
            cout << " GAME OVER.\n";
            
            
        }