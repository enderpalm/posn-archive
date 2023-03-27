#include <bits/stdc++.h>

#define MAX_SIZE 21

int size;

bool board[MAX_SIZE][MAX_SIZE];

void printBoard(){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++) printf("%c ", board[i][j] ? 'Q' : '.');
        std::cout << "\n";
    }
}

bool isSafe(int row, int col){
    // row
    for (int i = 0; i < col; i++)
        if (board[row][i]) return false;

    // ascending diag
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) return false;

    // descending diag
    for (int i = row, j = col; i < size && j >= 0; i++, j--)
        if (board[i][j]) return false;

    return true;
}
   
bool nQueenAttempt(int col=0){
    if (col == size) return true; // reach the end;
    for (int row = 0; row < size; row++){
        if (isSafe(row, col)){
            board[row][col] = true;;
            if (nQueenAttempt(col + 1)) return true;
            board[row][col] = false;
        }
    }
    return false;
}

int main(){
    std::cin >> size;
    memset(board, 0, sizeof(board));
    nQueenAttempt();
    printBoard();
    return 0;

}