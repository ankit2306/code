#include<bits/stdc++.h>
#define N 5
using namespace std;

void detonate(int arr[][N],int row,int b[][N])
{
    for(int i=row-1;i>=row-5;row--)
    {
        for(int j=0;j<N;j++)
            if(arr[i][j]==2)
            {
                b[i][j]=arr[i][j];
                arr[i][j]=0;
            }
    }
}

void undetonate(int arr[][N],int row,int b[][N])
{
    for(int i=row-1;i>=row-5;row--)
    {
        for(int j=0;j<N;j++)
            {
                arr[i][j]=b[i][j];
                b[i][j]=0;
            }
    }
}

void plane(int arr[][N],int row,int col,int score,bool *det,int* maxScore,int n,int b[][N])
{   
    if(row<0||row>=n||col<0||col>=N||score<0)
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

    if(arr[row][col]==0)
    {
        plane(arr,row-1,col-1,score,det,maxScore,n,b);
        plane(arr,row-1,col,score,det,maxScore,n,b);
        plane(arr,row-1,col+1,score,det,maxScore,n,b);

        if(det==false)
        {
        detonate(arr,row,b);
        *det==true;
        plane(arr,row-1,col-1,score,det,maxScore,n,b);
        plane(arr,row-1,col,score,det,maxScore,n,b);
        plane(arr,row-1,col+1,score,det,maxScore,n,b);
        }
    }
    else if(arr[row][col]=1)
    {
        plane(arr,row-1,col-1,score+1,det,maxScore,n,b);
        plane(arr,row-1,col,score+1,det,maxScore,n,b);
        plane(arr,row-1,col+1,score+1,det,maxScore,n,b);
        
        if(det==false)
        {
        detonate(arr,row,b);
        *det==true;
        plane(arr,row-1,col-1,score+1,det,maxScore,n,b);
        plane(arr,row-1,col,score+1,det,maxScore,n,b);
        plane(arr,row-1,col+1,score+1,det,maxScore,n,b);
        }
    }
    else{
        plane(arr,row-1,col-1,score-1,det,maxScore,n,b);
        plane(arr,row-1,col,score-1,det,maxScore,n,b);
        plane(arr,row-1,col+1,score-1,det,maxScore,n,b);

        if(det==false)
        {
        detonate(arr,row,b);
        *det==true;
        plane(arr,row-1,col-1,score-1,det,maxScore,n,b);
        plane(arr,row-1,col,score-1,det,maxScore,n,b);
        plane(arr,row-1,col+1,score-1,det,maxScore,n,b);
        }
    }
    undetonate(arr,row,b);
    *det=false;
}

int main()
{
    int n,maxScore=INT_MIN;
    bool det=false;
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

    plane(arr,n-1,N/2-1,0,&det,&maxScore,n,b);
    plane(arr,n-1,N/2,0,&det,&maxScore,n,b);
    plane(arr,n-1,N/2+1,0,&det,&maxScore,n,b);

    detonate(arr,n,b);
    det=true;
    plane(arr,n-1,N/2-1,0,&det,&maxScore,n,b);
    plane(arr,n-1,N/2,0,&det,&maxScore,n,b);
    plane(arr,n-1,N/2+1,0,&det,&maxScore,n,b);

    cout<<maxScore;
    return 0;
}