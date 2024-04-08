#include <iostream>
using namespace std;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

void initializeBoard(char board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = EMPTY;
        }
    }
}

void printBoard(char board[3][3])
{
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; i++)
    {
        cout << i << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << board[i][j];
            if (j < 2)
                cout << "|";
        }
        cout << "\n";
        if (i < 2)
            cout << "  -+-+-\n";
    }
}

bool isWin(char player, char board[3][3])
{
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++)
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;

    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return true;

    return false;
}

bool isDraw(char board[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == EMPTY)
                return false;
    return true;
}

void playerTurn(char player, char board[3][3])
{
    int x, y;
    do
    {
        cout << "Player " << player << ", enter your move (row and column): ";
        cin >> x >> y;
    } while (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != EMPTY);

    board[x][y] = player;
}

int main()
{
    char board[3][3];
    char currentPlayer = PLAYER_X;

    initializeBoard(board);

    while (true)
    {
        printBoard(board);
        playerTurn(currentPlayer, board);

        if (isWin(currentPlayer, board))
        {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        else if (isDraw(board))
        {
            printBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
    }

    return 0;
}
