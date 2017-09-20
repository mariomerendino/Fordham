//TicTacToe.cpp
//Author: Mario Merendino
//Professor Papadakis
//This Lab allows 2 players to play a game of tictactoe
//Last Modified: September 13, 2015


#include <iostream>
using namespace std;

char player= 'X';
char winner= 'A';
char board[3][3]={ '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char ans;
void display();
void input();
void playerswap();
void resetarray();
char checkwinner();

int main()
{
    int turn(0);
    char playagain;
    display(); //Displays a fresh board
    do
    {
        turn++;
        if(turn > 9)
        {
            cout << "There is a Tie!" << endl << "Would You like to play again? (Y or N)";
            cin >> playagain;
            if(playagain== 'Y' || playagain== 'y')
            {
                resetarray();
                main();
            }
            else
            {
                return 0;
            }
        }
        
        input(); //Takes each players input
        display(); //Displays the Updated board
        checkwinner(); //Checks if the current player is the winner
        playerswap(); //Switches players
    }while(winner== 'A'); //Do-While loop works until the Winner is X or O
    if (winner== 'X')
    {
        cout << "Player X is the winner!" << endl << "Would You like to play again? (Y or N)";
        cin >> playagain;
        if(playagain== 'Y' || playagain== 'y')
        {
            resetarray();
            main();
        }
    }
    else if(winner=='O')
    {
        cout << "Player O is the winner!"<< endl << "Would You like to play again? (Y or N)";
        cin >> playagain;
        if(playagain== 'Y' || playagain== 'y')
        {
            resetarray();
            main();
        }
    }
    
}
void display()//Displays the Game board
{
    cout << " TIC-TAC-TOE" << endl; //Title of board
    for (int r = 0; r < 3; r++)
    {
        cout << "+---+---+---+" << endl;
        for(int c=0; c< 3; c++)
        {
            cout << "| " << board[r][c] << " ";
        }
        cout << "|" << endl;
        if ((r+1) % 3 == 0 && r != 0) {
        cout << "+---+---+---+" << endl;
        }
    }
}
void input()
{
    char ans;
    cout << "Player " << player << ", your move!" << endl;
    cin >> ans;
    switch (ans)
    {
            case '1'://Top Left
                if(board[0][0]=='X' || board[0][0]=='O') //Checks if space is available
                {
                    cout << "That space is occupied!";
                    input();
                }
                board[0][0]=player; //uses the space if its available
                break;
            case '2'://Top Middle
                if(board[0][1]=='X' || board[0][1]=='O')
                {
                    cout << "That space is occupied!";
                    input();
                }
                board[0][1]=player;
                break;
            case '3'://Top Right
                if(board[0][2]=='X' || board[0][2]=='O')
                {
                    cout << "That space is occupied!";
                    input();
                }
                board[0][2]=player;
                break;
            case '4'://Middle Left
                if(board[1][0]=='X' || board[1][0]=='O')
                {
                    cout << "That space is occupied!";
                    input();
                }
                board[1][0]=player;
                break;
            case '5'://Center
                if(board[1][1]=='X' || board[1][1]=='O')
                {
                    cout << "That space is occupied!";
                    input();
                }
                board[1][1]=player;
                break;
            case '6'://Middle right
                if(board[1][2]=='X' || board[1][2]=='O')
                {
                    cout << "That space is occupied!";
                    input();
                }
                board[1][2]=player;
                break;
            case '7'://Bottom left
                if(board[2][0]=='X' || board[2][0]=='O')
                {
                    cout << "That space is occupied!";
                    input();
                }
                board[2][0]=player;
                break;
            case '8'://Bottom middle
                if(board[2][1]=='X' || board[2][1]=='O')
                {
                    cout << "That space is occupied!";
                    input();
                }
                board[2][1]=player;
                break;
            case '9'://Bottom right
                if(board[2][2]=='X' || board[2][2]=='O')
                {
                    cout << "That space is occupied!";
                    input();
                }
                board[2][2]=player;
                break;
            default:
                cout << endl << "That space is not on the Board!" << endl;
                input();
    }
}

void playerswap() //Changes the player every other round
{
    if(player== 'X')
        player='O';
    else
        player='X';
}
char checkwinner() //Checks to see the winner
{
    if (board[0][0]== 'X' && board[0][1]== 'X' && board[0][2]== 'X')//X is winner with top row horizontal
        winner= 'X';

    else if (board[0][0]== 'O' && board[0][1]== 'O' && board[0][2]== 'O')//O is winner wiht top row horizontal
        winner= 'O';

    else if(board[1][0]== 'X' && board[1][1]== 'X' && board[1][2]== 'X')//X is winner with middle row horizontal
        winner='X';

    else if(board[1][0]== 'O' && board[1][1]== 'O' && board[1][2]== 'O')//O is winner with middle row horizontal
        winner='O';

    else if(board[2][0]== 'X' && board[2][1]== 'X' && board[2][2]== 'X')//X is winner with bottom row horizontal
        winner='X';

    else if(board[2][0]== 'O' && board[2][1]== 'O' && board[2][2]== 'O')//0 is winner with bottom row horizontal
        winner='O';

    else if(board[0][0]== 'X' && board[1][0]== 'X' && board[2][0]== 'X')//X is winner with first column vertical
        winner='X';

    else if(board[0][0]== 'O' && board[1][0]== 'O' && board[2][0]== 'O')//O is winner with first column vertical
        winner='O';
    
    else if(board[0][1]== 'X' && board[1][1]== 'X' && board[2][1]== 'X')//X is winner with second column vertical
        winner='X';
    
    else if(board[0][1]== 'O' && board[1][1]== 'O' && board[2][1]== 'O')//X is winner with second column vertical
        winner='O';
    
    else if(board[0][2]== 'X' && board[1][2]== 'X' && board[2][2]== 'X')//X is winner with thrid column vertical
        winner='X';
    
    else if(board[0][2]== 'O' && board[1][2]== 'O' && board[2][2]== 'O')//O is winner with thrid column vertical
        winner='O';
    
    else if(board[0][0]== 'X' && board[1][1]== 'X' && board[2][2]== 'X')//X is winner with down diagonal
        winner='X';
    
    else if(board[0][0]== 'O' && board[1][1]== 'O' && board[2][2]== 'O')//O is winner with down diagonal
        winner='O';
    
    else if(board[2][0]== 'X' && board[1][1]== 'X' && board[0][2]== 'X')//X is winner with diagonal
        winner='X';
    
    else if(board[2][0]== 'O' && board[1][1]== 'O' && board[0][2]== 'O')//O is winner with diagonal
        winner='O';
    else
        winner='A';
    return(winner);
}
void resetarray()
{
    board[0][0]='1';
    board[0][1]='2';
    board[0][2]='3';
    board[1][0]='4';
    board[1][1]='5';
    board[1][2]='6';
    board[2][0]='7';
    board[2][1]='8';
    board[2][2]='9';
}