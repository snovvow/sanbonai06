#include<iostream>
#include<vector>
#include<queue>
#include<string>
#define MAX 500001
using namespace std;
int destination[1001];
struct disJoinSet{
  vector<int>parent,rank;
  disJoinSet(int n):parent(n),rank(n,1){
    for(int i=0;i<n;i++)
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
    return;
  }
 
};
bool add[MAX]={0,};
int main()
{
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n,m;
  
  cin>>n>>m;
  disJoinSet set(n);
  int a,b,i;
  for(i=1;i<=m;i++)
  {
    cin>>a>>b;
    if(set.find(a)==set.find(b))
    {
    	cout<<i<<"\n";
    	return 0;
    }
    else{
      set.merge(a,b);
    }
  }
  cout<<0<<"\n";
}