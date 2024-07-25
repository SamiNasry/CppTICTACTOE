#include <iostream>
#include <string>

using namespace std;

int move_nbr{}; // Number of moves done by the player

string player1{'1'}, player2{'2'};
string board[3][3] = {
    {" ", " " ," "} ,
    {" ", " " ," "} ,
    {" ", " " ," "} 
};
bool game_still = true;

void printboard(string (&arr)[3][3])
{
    for(int i{} ; i < 3 ; i++)
    {
        for (int j{} ; j < 3 ; j++)
        {
            cout << arr[i][j];
            if (j < 2) cout << "  | " ;
        }
        cout << endl;
        if (i < 2) cout << "------------" ; 
        cout << endl;
    }
}


bool check_win(string (&arr)[3][3])
{
    if (((arr[0][0] == arr[0][1] && arr[0][0] == arr[0][2]) && (arr[0][0] != " ")) ||
        ((arr[0][0] == arr[1][0] && arr[0][0] == arr[2][0]) && (arr[0][0] != " ")) ||
        ((arr[2][0] == arr[2][1] && arr[2][0] == arr[2][2]) && (arr[2][0] != " " )) ||
        ((arr[2][2] == arr[1][2] && arr[2][2] == arr[0][2]) && (arr[0][2] != " " ))||
        ((arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) && (arr[0][0] != " ")) ||
        ((arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]) && (arr[2][0] != " ")))
        {
            game_still = false;
            return true;
        } 

    else return false; 
}

bool check_draw(string (&arr)[3][3])
{
    if (move_nbr == 9)
    {
        if (!check_win(arr))
        {
            game_still = false;
            return true;
        }

        else return false;
    }
    else return false;
    
}

bool end_turn(string player)
{
    if (check_win(board))
    {
        cout << "Good win " << player << endl;
        return true;
    }
    else if (check_draw(board))
    {
        cout << "It's a draw " << endl;
        return true;
    } 

    return false;
    
}
int main()
{
    // Welcome player and print board
    cout << "Welcome to the Tic Tac Toe game :) " << endl;
    cout << "Player 1 name : " ;
    cin >> player1;
    cout << endl << "Player 2 name : " ;
    cin >> player2;
    printboard(board);

    while (game_still)
    {
        int move[2] = {0,0};

        cout << player1 << " it's your turn enter your move (row column) : " ;
        cin >>  move[0] >> move[1];
        move_nbr++;
        int row = move[0];
        int column = move[1];
        board[(row - 1)][(column - 1)] = "O" ;
        printboard(board);
        if (end_turn(player1))
        {
            break;
        } 

        cout << player2 << " it's your turn enter your move (row column) : " ;
        cin >>  move[0] >> move[1];
        move_nbr++;
        row = move[0];
        column = move[1];
        board[(row - 1)][(column - 1)] = "X" ;
        printboard(board);
        if (end_turn(player2))
        {
            break;
        }
        
   
    }

    cout << "The game is over bye bye :):):)" << endl;
    
}