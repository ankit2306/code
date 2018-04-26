#include<bits/stdc++.h>
#define N 10
using namespace std;

bool inRange(int x,int y,int n,bool visited[][N])
{
    if(x<0||x>=n||y<0||y>=n||visited[x][y]==true)
        return false;
    else
        return true;
}

void printArr(int arr[][N],int n)
{
    for(int i=n-1;i>=0;i--)
    {   
        for(int j=0;j<n;j++)
        {
            cout<<setw(2)<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n\n";
}

void kTour(int arr[][N],int x,int y,int movx[],int movy[],int n,int iter,bool visited[][N])
{
    visited[x][y]=true;
    arr[x][y]=iter;

    if(iter>=n*n)
    {
        printArr(arr,n);
        //arr[x][y]=0;
        visited[x][y]=false;
        return;
    }
        
        for(int i=0;i<8;i++)
        {
            int x_new=x+movx[i];
            int y_new=y+movy[i];
            if(inRange(x_new,y_new,n,visited))
            {
                kTour(arr,x_new,y_new,movx,movy,n,iter+1,visited);
            }
        }
        visited[x][y]=false;
        //arr[x][y]=0;
}

int main()
{
    int arr[N][N],n;
    bool visited[N][N];
    int movx[8]={ 2, 1, -1, -2, -2, -1,  1,  2 };
    int movy[8]={ 1, 2,  2,  1, -1, -2, -2, -1 };
    cout<<"Enter the value of n: ";
    cin>>n;
    if(n>N)
    {
        cout<<"Invalid input !!!"<<endl;
        return 0;
    }
    for(int i=0;i<N;i++)
    for(int j=0;j<N;j++)
    {
        arr[i][j]=0;
        visited[i][j]=false;
    }
    int init_x,init_y;
    cout<<"Enter initial x coordinate: ";
    cin>>init_x;
    cout<<"Enter initial y coordinate: ";
    cin>>init_y;
    if(inRange(init_x-1,init_y-1,n,visited))
        kTour(arr,init_x-1,init_y-1,movx,movy,n,1,visited);
    else
        cout<<"Entered position does not lie on the board !!!\n";
    return 0;
}