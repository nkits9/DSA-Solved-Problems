#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool isVacant(vvi &mat, int &row, int &col) {
    for(row=0; row<9; row++) {
        for(col=0; col<9; col++) {
            if(mat[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool isRowValid(vvi &mat, int row, int num) {
    for(int col=0; col<9; col++) {
        if(mat[row][col] == num)
            return false;
    }
    return true;
}

bool isColValid(vvi &mat, int col, int num) {
    for(int row=0; row<9; row++) {
        if(mat[row][col] == num) 
            return false;     
    }
    return true;
}

bool isBoardValid(vvi &mat, int row, int col, int num) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(mat[i+row][j+col]==num)
                return false;
        }
    }
    return true;
}

bool isValid(vvi &mat, int row, int col, int num) {
    return isRowValid(mat, row, num) && 
           isColValid(mat, col, num) && 
           isBoardValid(mat, row-row%3, col-col%3, num);
}

bool solveSudoku(vvi &mat) {
    int row, col;
    if(!isVacant(mat, row, col))   
        return true;

    for(int num=1; num<=9; num++) {
        if(isValid(mat, row, col, num)) {
            mat[row][col] = num;
            
            if(solveSudoku(mat)) 
                return true;
            
            mat[row][col]=0;
        }
    }
    return false; 
}

void printSudoku(vvi &mat) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cout << mat[i][j] << " ";
        }
    }
    cout << endl;
}


int main() {
    int t; cin >> t;
    while(t--) {
        vvi mat(9,vi(9));
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                cin >> mat[i][j];
            }
        }
        if(solveSudoku(mat)) 
            printSudoku(mat);
        else 
            cout << "No solution exists" << endl;
    }
}
