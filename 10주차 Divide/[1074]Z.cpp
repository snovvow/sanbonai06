#include<iostream>
#include<stdio.h>
using namespace std;

int map[64][64];
int cnt=0;
int breakPoint=0;
int findX,findY;
int N;



/*void divide(int x,int y,int h)
{
  if(breakPoint==1) return;
  if(x==findX&&y==findY) breakPoint++;
  else if(h==1) cnt++;
  for(int i=x;i<x+h;i++)
  {
    for(int j=y;j<y+h;j++)
    {
      if(h>1)
      {
        int d=h/2;
        divide(x,y,d);
        divide(x,y+d,d);
        divide(x+d,y,d);
        divide(x+d,y+d,d);
        return;
      }
    }
  }
}*/
void find(int x,int y,int N)
{
  if(N==2)
  {
    if(x<1&&y<1) cnt+=0;
    else if(x<1&&y==1) cnt++;
    else if(x==1&&y<1) cnt+=2;
    else cnt+=3;
    return;
  }
  //findX=findX-N/2;
  //findY=findY-N/2;
  if(x<N/2&&y<N/2){
    find(x,y,N/2);
  }  //1사분면
  else if(x<N/2&&y>=N/2){
    y=y-N/2;
    find(x,y,N/2);
    cnt+=(N/2)*(N/2);
  } //2사분면
  else if(x>=N/2&&y<N/2){
    x=x-N/2;
    find(x,y,N/2);
    cnt+=N*N/2;
  } //3사분면
  else{
    x=x-N/2;
    y=y-N/2;
    find(x,y,N/2);
    cnt+=N*N*0.75;
  } //4사분면
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>N>>findX>>findY;
  N=1<<N;
  find(findX,findY,N);
  cout<<cnt;
}