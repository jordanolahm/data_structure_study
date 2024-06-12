#include <iostream>
#include <vector>

using namespace std; 


bool isSafe(vector<vector<int>>& board, int row, int col, int N) {
    for(int i =0; i < row; i++) {
        if(board[i][col] == 1) {
            return false; 
        }
    }

    for(int i = row, j = col; i>= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1) { 
            return false;
        }
    }

     for(int i = row, j = col; i>= 0 && j < N; i--, j++) {
        if(board[i][j] == 1) { 
            return false;
        }
    }

    return true; 
}

bool solveQueenUtil(vector<vector<int>>& board, int row, int N) {
    if(row >= N) {
        return true;
    }
    for(int i = 0; i < N; i++) {
        
        if(isSafe(board,row,i,N)) {
            board[row][i] = 1; 

            if(solveQueenUtil(board, row + 1, N)) {
                return true; 
            }

            board[row][i] = 0; 
        }
    }
    return false; 
}

bool solveNQueens(int N) {
    vector<vector<int>> board(N, vector<int>(N,0)); 

    if(solveQueenUtil(board, 0, N) == false){
        cout << "Solution does not exist" << endl; 
        return false;
    }


    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout<< board[i][j] << " " << endl; 
        }
        cout << endl; 
    }

    return true; 
}


int main () {
    int N = 0; 

    cout << "Enter the number of queens(N): "; 
    cin >> N; 

    solveNQueens(N); 
    
    return 0; 
}