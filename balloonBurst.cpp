#include<bits/stdc++.h>
using namespace std;

void shootBalloon(int score,int i,bool shot[],int arr[],int numShot,int n,int *maxScore,int order[],int storeOrder[])
{
    shot[i]=true;
    order[numShot-1]=arr[i-1];
    int left,right;
    for(left=i-1;left>=0;)
    {
        if(shot[left]==false)
        break;
    }
    for(right=i+1;right<=n+1;)
    {
        if(shot[right]==false)
        break;
    }

    score+=arr[left]*arr[right];

    if(numShot==n && score>(*maxScore))
    {
        *maxScore=score;
        for(int i=0;i<n;i++)
            storeOrder[i]=order[i];
        return;
    }

    for(int j=1;j<=n;j++)
    {
        if(shot[j]==false)
            shootBalloon(score,j,shot,arr,numShot+1,n,maxScore,order,storeOrder);
    }
    shot[i]=false;
    order[numShot-1]=0;
}

int main()
{
    int n,maxScore=INT_MIN,max=INT_MIN;
    cout<<"Enter the value of n: ";
    cin>>n;
    int arr[n+2],order[n],storeOrder[n];
    bool shot[n+2];
    memset(shot,false,sizeof(shot));
    memset(order,0,sizeof(order));
    cout<<"Enter the array: ";
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    arr[0]=arr[n+1]=1;

    for(int i=1;i<=n;i++)
    {   
        shootBalloon(0,i,shot,arr,1,n,&maxScore,order,storeOrder);
        if(maxScore>max)
        {
            max=maxScore;
        }
    }
    cout<<max<<endl;
    for(int i=0;i<n;i++)
        cout<<storeOrder[i]<<" ";
    cout<<endl;

    return 0;
}