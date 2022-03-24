#include<iostream>
#include<queue>
using namespace std;

int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
int map[1000][1000];
bool visited[1000][1000];
int day[1000][1000];
int state[1000][1000];

struct xy {
 int y;
 int x;
};
queue<xy>q;
queue<xy>q1;
void init()
{
  for(int i=0;i<1000;i++)
  {
    for(int j=0;j<1000;j++)
    {
      visited[i][j]=0;
    }
  }
}
int max(int a,int b)
{
	if(a<=b) return b;
	else return a;
}
int min(int a,int b)
{
	if(a<=b) return a;
	else return b;
}
void BFS(int start_Y,int start_X,int size_y,int size_x)
{
  int x,y;
  //q.push({Y,X});
  visited[start_Y][start_X]=1;
  while(q.empty()!=1)
  {
  	x=q.front().x;
    y=q.front().y;
    q.pop();
    for(int i=0;i<4;i++)
    {
      if(x+dx[i]>=0&&x+dx[i]<size_x&&y+dy[i]>=0&&y+dy[i]<size_y)
      {
        if(map[y+dy[i]][x+dx[i]]!=-1&&map[y+dy[i]][x+dx[i]]!=1&&visited[y+dy[i]][x+dx[i]]==0)
        {
          q.push({y+dy[i],x+dx[i]});
          visited[y+dy[i]][x+dx[i]]=1;
          state[y+dy[i]][x+dx[i]]=1;
          if(day[y+dy[i]][x+dx[i]]==0) day[y+dy[i]][x+dx[i]]=day[y][x]+1;
          else day[y+dy[i]][x+dx[i]]=min(day[y][x]+1,day[y+dy[i]][x+dx[i]]);
        }
      }
    }
  }
}

int BFS_find(int size_y,int size_x)
{
	int mx=day[0][0];
	for(int i=0;i<size_x;i++)
	{
		for(int j=0;j<size_y;j++)
		{
			mx=max(mx,day[i][j]);
			if(state[i][j]==0)
			{
				return mx=-1;
				
			}
		}
	}
	return mx;
}
int main()
{
  int M,N;
  cin>>M>>N;
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<M;j++)
    {
    	day[i][j]=0;
      cin>>map[i][j];
      if(map[i][j]==-1) day[i][j]=-1;
      if(map[i][j]==1){
      	//q1.push({i,j});
        q.push({i,j});
      }
      state[i][j]=map[i][j];
    }
  }

  /*while(q1.empty()==0)
  {
  	init();
  	BFS(q1.front().y,q1.front().x,N,M);
  	q1.pop();
  }*/
  BFS(q.front().y,q.front().x,N,M);

  cout<<BFS_find(M,N);
  
}