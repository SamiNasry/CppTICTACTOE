#include <iostream>
#include <string>
#include <array>

using namespace std;

const int BOARD_SIZE = 3;
bool game_still = true;

int move_nbr{}; // Number of moves done by the player

enum class Player { Empty = ' ' , X = 'X' , O = 'O'};

string player1{'1'}, player2{'2'};

array<array<Player, BOARD_SIZE>, BOARD_SIZE> board;




void printboard(const array<array<Player, BOARD_SIZE>, BOARD_SIZE>& arr)
{
    for(int i{} ; i < BOARD_SIZE ; i++)
    {
        for (int j{} ; j < BOARD_SIZE ; j++)
        {
            cout << static_cast<char>(board[i][j]);
            if (j < BOARD_SIZE - 1) cout << "  | " ;
        }
        cout << endl;
        if (i < BOARD_SIZE - 1) cout << "------------" << endl; 
        
    }
    cout << endl;
}



bool check_win(const array<array<Player, BOARD_SIZE> , BOARD_SIZE>& arr )
{
    for (int i{} ; i < BOARD_SIZE - 1 ; i++)
    {
        //Check Columns
        if (arr[0][i] != Player::Empty && arr[0][i] == arr[1][i] && arr[0][i] ==  arr[2][i]) return true;

        //Check Rows
        if (arr[i][0] != Player::Empty && arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) return true; 
    }
    //Check Diagonals
    if (arr[0][0] != Player::Empty && arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) return true;
    if (arr[0][2] != Player::Empty && arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]) return true;
}

bool check_draw()
{
    return (move_nbr == BOARD_SIZE * BOARD_SIZE) && (!check_win(board)); 
}

bool end_turn(const string& player)
{
    if (check_win(board))
    {
        cout << "Congratulations " << player << ", you win :)" <<  endl;
        return true;
    }
    else if (check_draw())
    {
        cout << "It's a draw " << endl;
        return true;
    } 

    return false;
    
}

void PlayerTurn(const string& player_name, Player symbol)
{
    int row{}, col{};
    do {
        cout << player_name << " , enter your move [row colum] : " ;
        cin >> row >> col ;
        row-- ; col--; // Adjust for 0-based index;
    }
    while ( row < 0 || row > BOARD_SIZE || col < 0 || col > BOARD_SIZE || board[row][col] != Player::Empty);

    board[row][col] = symbol;
    move_nbr++;
    printboard(board);
}

void GameLoop()
{
    while (game_still)
    {
        PlayerTurn(player1 , Player::O);
        if (end_turn(player1))
        {
            game_still = false;
            break;
        }
        else{
            PlayerTurn(player2 , Player::X);
            if(end_turn(player2))
            {
                game_still = false;
                break;
            }
        }
    }
}


int main()
{

    for(auto& row : board)
    {
        row.fill(Player::Empty);
    }
    

    cout << "Welcome to the Tic Tac Toe game :) " << endl;
    cout << "Player 1 name : " ;
    cin >> player1;
    cout << endl << "Player 2 name : " ;
    cin >> player2;

    printboard(board);
    GameLoop();

    cout << "The game is over, thanks for playing :)" << endl;
    return 0;

       
}