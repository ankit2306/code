#include<bits/stdc++.h>
using namespace std;

void shootBalloon(int score,int i,bool shot[],int arr[],int numShot,int n,int *maxScore,int order[],int storeOrder[])
{
   // cout<<"Function evoked"<<endl;
    shot[i]=true;
    order[numShot-1]=arr[i];
   // cout<<(int)shot[i];
   // cout<<" "<<order[numShot-1]<<endl;

    int left,right;
    for(left=i-1;left>=0;left--)
    {
        if(shot[left]==false)
            break;
    }
    for(right=i+1;right<=n+1;right++)
    {
        if(shot[right]==false)
            break;
    }

    score+=arr[left]*arr[right];
    //cout<<left<<" "<<right<<endl;

    if(numShot==n)
    {
        if(score>(*maxScore))
        {
            *maxScore=score;
            for(int k=0;k<n;k++)
                storeOrder[k]=order[k];
        }
        shot[i]=false;
        order[numShot-1]=0;
        return;
    }

    for(int j=1;j<=n;j++)
    {
        if((shot[j]==false) && (numShot<n))
        {
            cout<<j<<endl;
            shootBalloon(score+arr[left]*arr[right],j,shot,arr,numShot+1,n,maxScore,order,storeOrder);
        }
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


//  check code:
/*    for (int i=0;i<n+2;i++)
    {
        cout<<setw(2)<<arr[i]<<" "<<shot[i];
        cout<<endl;
    }   
*/
    for(int i=1;i<=n;i++)
    {   
        shootBalloon(0,1,shot,arr,1,n,&maxScore,order,storeOrder);
    }
    cout<<maxScore<<endl;
    for(int i=0;i<n;i++)
        cout<<storeOrder[i]<<" ";
    cout<<endl;

    return 0;
}
