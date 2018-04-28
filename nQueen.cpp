#include<bits/stdc++.h>
#define N 10
using namespace std;

bool isnotAttacking(int board[N][N],int x,int y,int n)
{
    if(x<0||x>=n||y<0||y>=n)        //checking board
        return false;
    
    for(int i=y;i>=0;i--)           //checking left row
        if(board[x][i]==1)
            return false;

    for(int i=x;i>=0;i--)           //checking top column
        if(board[i][y]==1)
            return false;

    for(int i=x,j=y;i>=0&&j>=0;i--,j--)     //checking top-left diagonal
        if(board[i][j]==1)
            return false;

    for(int i=x,j=y;i<n&&j>=0;i++,j--)     //checking bottom-left diagonal
        if(board[i][j]==1)
            return false;

    return true;
}

void printBoard(int board[N][N],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<setw(2)<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void solveQueen(int board[N][N],int x,int y,int n)
{
    if(y==n)
    {
        printBoard(board,n);
        return;
    }

    board[x][y]=1;

    for(int i=0;i<n;i++)
    {
        if(isnotAttacking(board,i,y+1,n))
            solveQueen(board,i,y+1,n);
    }
    board[x][y]=0;
}

int main()
{
    int n,Num;
    int board[N][N];
    cout<<"Enter the size of board: ";
    cin>>n;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            board[i][j]=0;

    for(int i=0;i<n;i++)
        solveQueen(board,i,0,n);

    return 0;
}