#include <iostream>
#include <vector>
#include <unordered_set>

class Solution{
    public:
    bool validSudoku (std::vector<std::vector<char>> &board){
    // Check row
    for (int row = 0; row < 9; row++){
        std::unordered_set<char> checkRow;
        for (int col = 0; col < 9; col++){
            if (board[row][col] != '.' && checkRow.count(board[row][col])){
                return false;
            }checkRow.insert(board[row][col]);
        }
        }
    for (int col = 0; col < 9; col++){
        std::unordered_set<char> checkCol;
        for (int row = 0; row < 9; row++){
            if(board[row][col] != '.' && checkCol.count(board[row][col])){
                return false;
            }checkCol.insert(board[row][col]);
        }
    }
    std::unordered_set<char> checkSubBox[9];
    for (int row = 0; row < 9; row++){
        for(int col = 0; col < 9; col++){
            int subBox = (row/3) * 3 + col/3;
            if (board[row][col] != '.' && checkSubBox[subBox].count(board[row][col])){
                return false;
            }checkSubBox[subBox].insert(board[row][col]);
        }
    }
    return true;
    }
    };


int main() {
    Solution solution;

    // Example 1
    std::vector<std::vector<char>> board1 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    std::cout << "Example 1 - Is valid Sudoku? " << (solution.validSudoku(board1) ? "True" : "False") << std::endl;

    // Example 2
    std::vector<std::vector<char>> board2 = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    std::cout << "Example 2 - Is valid Sudoku? " << (solution.validSudoku(board2) ? "True" : "False") << std::endl;

    return 0;
}