#include<iostream>
#include<vector>
#include<queue>
#define MAX 201
using namespace std;
int destination[1001];
struct disJoinSet{
  vector<int>parent,rank;
  disJoinSet(int n):parent(n+1),rank(n+1,1){
    for(int i=1;i<=n;i++)
    parent[i]=i;
  }
  int find(int u){
    if(u==parent[u]) return u;
    parent[u]=find(parent[u]);
    return parent[u];
  }
  void merge(int u,int v)
  {
    u=find(u); v=find(v);
    if(u==v) return;
    if(rank[u]>rank[v]) swap(u,v);
    parent[u]=v;
    if(rank[u]==rank[v]) rank[v]++;
  }
};
bool adj[MAX][MAX];
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  int N,M;
  cin>>N;
  cin>>M;
  int a;
  disJoinSet set(N);
  for(int i=1;i<=N;i++)
  {
    for(int j=1;j<=N;j++)
    {
        cin>>a;
        if(a==1) set.merge(i,j);
    }
  }
  int ret;
  for(int i=0;i<M;i++)
  {
    cin>>destination[i];
    ret=set.find(destination[0]);
    if(ret!=set.find(destination[i])){
      cout<<"NO";
      break;
    }
  }
  if(ret==set.find(destination[M-1])) cout<<"YES";
  
}