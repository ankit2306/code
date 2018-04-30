#include<bits/stdc++.h>
#define N 5
using namespace std;

void detonate(int arr[][N],int row,int b[][N])
{
    for(int i=row-1;i>=row-5;row--)
    {
        for(int j=0;j<N;j++)
        {
            if(arr[i][j]==2)
            {
                b[i][j]=arr[i][j];
                arr[i][j]=0;
            }
        }
    }
}

void undetonate(int arr[][N],int row,int b[][N])
{
    for(int i=row-1;i>=row-5;row--)
    {
        for(int j=0;j<N;j++)
            {
                if(b[i][j]==2)
                {
                    arr[i][j]=b[i][j];
                    b[i][j]=0;
                }
            }
    }
}

int calcScore(int arr[][N],int row,int col)
{
    switch(arr[row][col])
    {
        case 0:
            return 0;
        case 1:
            return 1;
        case 2:
            return -1;
    }
}

void plane(int arr[][N],int row,int col,int score,int* maxScore,int n)
{   
    if(row<0||row>=n||col<0||col>=N)
        return;
    if(score<0)
    {
        if(score>(*maxScore))
            (*maxScore)=score;
        return;
    }
    if(row==0)
    {
        if(score+arr[row][col]>(*maxScore))
        {
            *maxScore=score+arr[row][col];
        }
        return;
    }

    plane(arr,row-1,col-1,score+calcScore(arr,row-1,col-1),maxScore,n);
    plane(arr,row-1,col,score+calcScore(arr,row-1,col),maxScore,n);
    plane(arr,row-1,col+1,score+calcScore(arr,row-1,col+1),maxScore,n);
}

int main()
{
    int n,maxScore=INT_MIN;
    cout<<"Enter the vale of n: ";
    cin>>n;
    int arr[n][N],b[n][N];
    cout<<"Enter the array: \n";
    for(int i=0;i<n;i++)
        for(int j=0;j<N;j++)
        {
            cin>>arr[i][j];
            b[i][j]=0;
        }

    for(int i=n;i>4;i--)
    {
        detonate(arr,i,b);
        plane(arr,i-1,1,calcScore(arr,i-1,1),&maxScore,n);
        plane(arr,i-1,2,calcScore(arr,i-1,2),&maxScore,n);
        plane(arr,i-1,3,calcScore(arr,i-1,3),&maxScore,n);
        undetonate(arr,i,b);
    }
    cout<<maxScore;
    return 0;
}