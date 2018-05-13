#include<iostream>
#include<stack>
#include<climits>
#define N 10
using namespace std;
stack< pair<int,int> > st;
int r_odd[6]={0,-1,0,1,1,1};
int c_odd[6]={-1,0,1,1,0,-1};
int r_even[6]={-1,-1,-1,0,1,0};
int c_even[6]={-1,0,1,1,0,-1};

bool isSafe(int x,int y,int n,int m,bool visited[][N])
{
    if(x<0||x>=m||y<0||y>=n||visited[x][y]==true)
        return false;
    else return true;
}

void dfs(int cell[][N],int row,int col,int depth,int score,int *maxScore,bool visited[][N],int n,int m)
{
    visited[row][col]=true;
    score+=cell[row][col];
    if(depth==1)
    {
        if(score>*maxScore)
            *maxScore=score;
        visited[row][col]=false;
        return;
    }

    if(col%2==0)
    {
        for(int i=0;i<6;i++)
        {
            int x_n=row+r_even[i];
            int y_n=col+c_even[i];
            if(isSafe(x_n,y_n,n,m,visited))
            {
                dfs(cell,x_n,y_n,depth-1,score,maxScore,visited,n,m);
                //st.push(make_pair(x_n,y_n));
            }
        }
    }

    else
    {
        for(int i=0;i<6;i++)
        {
            int x_n=row+r_odd[i];
            int y_n=col+c_odd[i];
            if(isSafe(x_n,y_n,n,m,visited))
            {
                dfs(cell,x_n,y_n,depth-1,score,maxScore,visited,n,m);
                //st.push(make_pair(x_n,y_n));
            }
        }
    }
    /*int x=st.top().first;
    int y=st.top().second;
    st.pop();
    dfs(cell,x,y,depth-1,score,maxScore,visited,n,m);*/
    visited[row][col]=false;
}

void bfs(int cell[][N],int row,int col,int depth,int score,int *maxScore,bool visited[][N],int n,int m)
{
    visited[row][col]=true;
    score+=cell[row][col];
    if(depth==1)
    {
        if(score>*maxScore)
            *maxScore=score;
        while(!st.empty())
            st.pop();
        visited[row][col]=false;
        return;
    }
    if(col%2==0)
    {
        for(int i=0;i<6;i++)
        {
            int x_n=row+r_even[i];
            int y_n=col+c_even[i];
            if(isSafe(x_n,y_n,n,m,visited))
            {
                //dfs(cell,x_n,y_n,depth-1,score,maxScore,visited,n,m);
                st.push(make_pair(x_n,y_n));
            }
        }
    }

    else
    {
        for(int i=0;i<6;i++)
        {
            int x_n=row+r_odd[i];
            int y_n=col+c_odd[i];
            if(isSafe(x_n,y_n,n,m,visited))
            {
                dfs(cell,x_n,y_n,depth-1,score,maxScore,visited,n,m);
                //st.push(make_pair(x_n,y_n));
            }
        }
    }
    /*int x=st.top().first;
    int y=st.top().second;
    st.pop();
    dfs(cell,x,y,depth-1,score,maxScore,visited,n,m);*/
    visited[row][col]=false;
}

int main()
{
    int m,n,maxScore=INT_MIN;
    cout<<"Enter no. of rows: ";
    cin>>m;
    cout<<"Enter no. of columns: ";
    cin>>n;
    int cell[m][N];
    bool visited[m][N];
    cout<<"Enter array:\n";
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>cell[i][j];
            visited[i][j]=false;
        }
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            dfs(cell,i,j,4,0,&maxScore,visited,n,m);
        }
    }

    cout<<maxScore<<endl;
    return 0;
}