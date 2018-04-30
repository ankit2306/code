#include<iostream>
using namespace std;

int fillposl(int spot[],int dist,int n,int gate,int fishermen,int gate_num)
{
    if(fishermen && spot[gate]==0)
    {
        spot[gate]=gate_num;
        dist+=1;
        fishermen--;
    }
    int i=1;
    while(fishermen)
    {
        if(gate-i>=0 && spot[gate-i]==0)
        {
            spot[gate-i]=gate_num;
            dist=dist+i+1;
            fishermen--;
        }
        if(gate+i<n && spot[gate+i]==0)
        {
            spot[gate+i]=gate_num;
            dist=dist+i+1;
            fishermen--;
        }
        i++;
    }
    return dist;
}

void unfillposl(int spot[],int n,int gate,int fishermen,int gate_num)
{
    if(fishermen && spot[gate]==gate_num)
    {
        spot[gate]=0;
        fishermen--;
    }
    int i=1;
    while(fishermen)
    {
        if(gate-i>=0 && spot[gate-i]==gate_num)
        {
            spot[gate-i]=0;
            fishermen--;
        }
        if(gate+i<n && spot[gate+i]==gate_num)
        {
            spot[gate+i]=0;
            fishermen--;
        }
        i++;
    }
}

int fillposr(int spot[],int dist,int n,int gate,int fishermen,int gate_num)
{
    if(fishermen && spot[gate]==0)
    {
        spot[gate]=gate_num;
        dist+=1;
        fishermen--;
    }
    int i=1;
    while(fishermen)
    {
        if(gate+i<n && spot[gate+i]==0)
        {
            spot[gate+i]=gate_num;
            dist=dist+i+1;
            fishermen--;
        }
        if(gate-i>=0 && spot[gate-i]==0)
        {
            spot[gate-i]=gate_num;
            dist=dist+i+1;
            fishermen--;
        }
        i++;
    }
    return dist;
}

void unfillposr(int spot[],int n,int gate,int fishermen,int gate_num)
{
    if(fishermen && spot[gate]==gate_num)
    {
        spot[gate]=0;
        fishermen--;
    }
    int i=1;
    while(fishermen)
    {
        if(gate+i<n && spot[gate+i]==gate_num)
        {
            spot[gate+i]=0;
            fishermen--;
        }
        if(gate-i>=0 && spot[gate-i]==gate_num)
        {
            spot[gate-i]=0;
            fishermen--;
        }
        i++;
    }
}

void fillSpots(int spot[],int n,int dist,int *minDist,int fishermen[],int gate[],int gate_num)
{
    if(fishermen[gate_num-1]==0)
    {
        if(dist<(*minDist))
            *minDist=dist;
    }
    for(int i=1;i<=gate_num;i++)
    {
        fillposl(spot,dist,n,gate[gate_num-1],fishermen[gate_num-1],gate_num);
        unfillposl(spot,n,gate[gate_num-1],fishermen[gate_num-1],gate_num);
        fillposr(spot,dist,n,gate[gate_num-1],fishermen[gate_num-1],gate_num);
    }
}

int main()
{

}