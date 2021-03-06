/*
    N-Queens problem
    ----------------
    Find a way to place N non-attacking queens on an N×N chessboard
	
    Time complexity
    ---------------
    O(N!), where N is the number of queens

    Space complexity
    ----------------
    O(1), constant amount of extra space
*/

#include<iostream>
using namespace std;
#define N 4

void PrintSolution(int board[N][N]){
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"------------------"<<endl;
}

bool isSafe(int board[N][N], int row, int col){
    for (int i=0;i<col;i++){
        if (board[row][i]==1) return false;
    }
    for (int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        if (board[i][j]==1) return false;
    }
    for (int i=row+1,j=col-1;i<N&&j>=0;i++,j--){
        if (board[i][j]==1) return false;
    }
    return true;
}

void NQueen(int board[N][N], int col, int &cnt){
    if (col>=N){
        cnt++;
        PrintSolution(board);
        return;
    }
    for (int i=0;i<N;i++){
        if (isSafe(board,i,col)){
            board[i][col]=1;
            NQueen(board, col+1, cnt);
            board[i][col]=0;
        }
    }
}

int main(){

    int board[N][N]={};
    int cnt=0;
    NQueen(board,0,cnt);
    cout<<"No of Sol:"<<cnt<<endl;
    if (cnt==0) cout<<"No Solution Exists: "<<endl;
    else cout<<"Following are the resultant check Board:"<<endl;
}

