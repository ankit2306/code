#include<iostream>
#define N 10
using namespace std;

bool inRange(int x,int y,int n,bool visited[][N])
{
    if(x<0||x>=n||y<0||y>=n||visited[x][y]==true)
        return false;
    else
        return true;
}

void kTour(int arr[][N],int x,int y,int n,int iter,bool visited[][N])
{
    if(inRange(x,y,n,visited))
    {
        visited[x][y]=true;
        arr[x][y]=iter;
        kTour(arr,x+2,y+1,n,iter+1,visited);
        kTour(arr,x+2,y-1,n,iter+1,visited);
        kTour(arr,x-2,y+1,n,iter+1,visited);
        kTour(arr,x-2,y-1,n,iter+1,visited);
        kTour(arr,x+1,y+2,n,iter+1,visited);
        kTour(arr,x+1,y-2,n,iter+1,visited);
        kTour(arr,x-1,y+2,n,iter+1,visited);
        kTour(arr,x-1,y-2,n,iter+1,visited);
    }
}

int main()
{
    int arr[N][N],n;
    bool visited[N][N];
    cout<<"Enter the value of n: ";
    cin>>n;
    if(n>N)
    {
        cout<<"Invalid input<<endl";
        return 0;
    }
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
    {
        arr[i][j]=0;
        visited[i][j]=false;
    }
    kTour(arr,0,0,n,1,visited);
    for(int i=0;i<n;i++)
    {   cout.precision(2);
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}