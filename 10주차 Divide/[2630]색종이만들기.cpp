#include<iostream>
using namespace std;

int map[128][128];
int one=0;
int zero=0;

void divide(int x,int y,int h)
{
  int color=map[x][y];
  for(int i=x;i<x+h;i++)
  {
    for(int j=y;j<y+h;j++)
    {
      if(map[i][j]!=color)
      {
        int d=h/2;
        divide(x,y,d);
        divide(x+d,y,d);
        divide(x,y+d,d);
        divide(x+d,y+d,d);
        return;

      }
    }
  }
  if(color==1) one++;
  else zero++;
}
int main()
{
  int N;
  cin>>N;
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      cin>>map[i][j];
    }
  }
  divide(0,0,N);
  cout<<zero<<'\n'<<one;
}