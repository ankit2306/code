#include<bits/stdc++.h>
#define N 10
using namespace std;

bool inRange(int maze[][N],bool visited[N][N],int x,int y,int n)
{
    if(x<0||x>=n||y<0||y>=n||maze[x][y]==0||visited[x][y]==true)
        return false;
    else
        return true;
}

void printSol(int sol[N][N],int n)
{
    for(int i=0;i<n;i++)
    {   
        for(int j=0;j<n;j++)
        {
            cout<<setw(2)<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n\n";
}

void solveMaze(int maze[N][N],int sol[N][N],int x,int y,int x_des,int y_des,int row[],int col[],int n,int iter,bool visited[N][N])
{
    visited[x][y]=true;
    sol[x][y]=iter;
    if((x==x_des) && (y==y_des))
    {
        printSol(sol,n);
        visited[x][y]=false;
        return;
    }
    for(int i=0;i<4;i++)
    {
        int x_new = x+col[i];
        int y_new = y+row[i];
        if(inRange(maze,visited,x_new,y_new,n))
        {
            solveMaze(maze,sol,x_new,y_new,x_des,y_des,row,col,n,iter+1,visited);
        }
    }
    visited[x][y]=false;
    sol[x][y]=0;
}

int main()
{
    int n,x_st,y_st,x_des,y_des;
    int row[4]={1, -1, 0, 0};
    int col[4]={0, 0, -1, 1};
    int sol[N][N],maze[N][N];
    bool visited[N][N];
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    {
        sol[i][j]=0;
        visited[i][j]=false;
        maze[i][j]=0;
    }

    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<"Enter the maze:\n";
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cin>>maze[i][j];

    cout<<"Enter the x_pos of starting location: ";
    cin>>x_st;
    cout<<"Enter the y_pos of starting location: ";
    cin>>y_st;
    cout<<"Enter the x_pos of destination location: ";
    cin>>x_des;
    cout<<"Enter the y_pos odestination location: ";
    cin>>y_des;

    if(inRange(maze,visited,x_st,y_st,n))
        solveMaze(maze,sol,x_st,y_st,x_des,y_des,row,col,n,1,visited);

    else
        cout<<"Invalid starting location  !!!\n";

    return 0;
}