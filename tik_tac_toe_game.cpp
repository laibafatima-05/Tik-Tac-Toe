#include <iostream>
#include <string>
using namespace std;

// PLAYER CLASS
class Player
{
private:
    string name;
    char symbol;
public:
    Player(string n, char s)
    {
        name = n;
        symbol = s;
    }
    string getName()
    {
        return name;
    }
    char getSymbol()
    {
        return symbol;
    }
};
// BOARD CLASS
class Board
{
private:
    char board[3][3];
public:
    Board()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                board[i][j] = ' ';
            }
        }
    }
    void displayBoard()
    {
        cout << "\n";
        cout << "     1   2   3\n";
        cout << "   -------------\n";

        for(int i = 0; i < 3; i++)
        {
            cout << i + 1 << "  |";
            for(int j = 0; j < 3; j++)
            {
                cout << " " << board[i][j] << " |";
            }
            cout << "\n   -------------\n";
        }
    }
    bool isPositionEmpty(int row, int col)
    {
        return board[row][col] == ' ';
    }
    void placeMark(int row, int col, char symbol)
    {
        board[row][col] = symbol;
    }
    bool checkWinner(char symbol)
    {
        // Check rows
        for(int i = 0; i < 3; i++)
        {
            if(board[i][0] == symbol &&
               board[i][1] == symbol &&
               board[i][2] == symbol)
            {
                return true;
            }
        }
        // Check columns
        for(int i = 0; i < 3; i++)
        {
            if(board[0][i] == symbol &&
               board[1][i] == symbol &&
               board[2][i] == symbol)
            {
                return true;
            }
        }
        // Check first diagonal
        if(board[0][0] == symbol &&
           board[1][1] == symbol &&
           board[2][2] == symbol)
        {
            return true;
        }
        // Check second diagonal
        if(board[0][2] == symbol &&
           board[1][1] == symbol &&
           board[2][0] == symbol)
        {
            return true;
        }
        return false;
    }
    bool isFull()
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(board[i][j] == ' ')
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// MAIN FUNCTION
int main()
{
    string name1, name2;
    char playAgain;

    cout << "\nTIC TAC TOE\n";

    cout << "\nEnter Player 1 name: ";
    cin >> name1;

    cout << "Enter Player 2 name: ";
    cin >> name2;

    Player player1(name1, 'X');
    Player player2(name2, 'O');

    do
    {
        Board gameBoard;

        int turn = 1;
        int row, col;

        while(true)
        {
            gameBoard.displayBoard();

            Player currentPlayer =
                (turn == 1) ? player1 : player2;

            cout << "\n" << currentPlayer.getName()
                 << "'s turn (" << currentPlayer.getSymbol() << ")\n";

            cout << "Enter row (1-3): ";
            cin >> row;

            cout << "Enter column (1-3): ";
            cin >> col;

            row--;
            col--;

            // Check invalid position
            if(row < 0 || row > 2 || col < 0 || col > 2)
            {
                cout << "\nInvalid position! Please try again.\n";
                continue;
            }
            // Check occupied position
            if(!gameBoard.isPositionEmpty(row, col))
            {
                cout << "\nPosition already occupied! Please try again.\n";
                continue;
            }
            // Place X or O
            gameBoard.placeMark(
                row,
                col,
                currentPlayer.getSymbol()
            );
            // Check winner
            if(gameBoard.checkWinner(currentPlayer.getSymbol()))
            {
                gameBoard.displayBoard();

                cout << "Winner: " << currentPlayer.getName() << "\n";
                cout << "Congratulations!\n";

                break;
            }
            // Check draw
            if(gameBoard.isFull())
            {
                gameBoard.displayBoard();

                cout << "\nGAME DRAW!\n";

                break;
            }

            // Change turn
            if(turn == 1)
            {
                turn = 2;
            }
            else
            {
                turn = 1;
            }
        }
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;
    }
     while(playAgain == 'Y' || playAgain == 'y');
    cout << "\nThank you for playing Tic Tac Toe!\n";

    return 0;
}