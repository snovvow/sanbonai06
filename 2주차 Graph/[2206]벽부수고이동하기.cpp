#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define MAX 1001
using namespace std;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int map[MAX][MAX];
int state[MAX][MAX][2];
int BFS(int size_Y,int size_X)
{
  queue<pair<pair<int,int>,int> > q;
  q.push(make_pair(make_pair(0,0),1));
  
  state[0][0][1]=1;
  while(!q.empty())
  {
    //cnt++;
    int x=q.front().first.second;
    int y=q.front().first.first;
    int block=q.front().second;
    q.pop();
    if(y==size_Y-1&&x==size_X-1)
    return state[size_Y-1][size_X-1][block];
    for(int i=0;i<4;i++)
    {
      if(y+dy[i]>=0&&y+dy[i]<size_Y&&x+dx[i]>=0&&x+dx[i]<size_X)
      {
        if(map[y+dy[i]][x+dx[i]]==1&&block)
        {
          state[y+dy[i]][x+dx[i]][block-1]=state[y][x][block]+1;
          q.push(make_pair(make_pair(y+dy[i],x+dx[i]),block-1));
         
        
        }
        else if(map[y+dy[i]][x+dx[i]]==0&&state[y+dy[i]][x+dx[i]][block]==0)
        {
          q.push(make_pair(make_pair(y+dy[i],x+dx[i]),block));
          state[y+dy[i]][x+dx[i]][block]=state[y][x][block]+1;
          
        }
      }
    }
  }
  return -1;
}

int main()
{
  int N,M;
  cin>>N>>M;
  for(int i=0;i<N;i++)
  {
  	string temp;
  	cin>>temp;
    for(int j=0;j<M;j++)
    map[i][j]=temp[j]-'0';
  }
cout<<BFS(N,M)<<endl;
  
}