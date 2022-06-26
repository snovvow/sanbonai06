#include<iostream>
#include<vector>
using namespace std;

int N;
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
int main() {
    cin>>N;
    int tmp = 1;
    disJoinSet set(N);
    for(int i=0; i<N-2; i++) {
        int a, b;
        cin>>a>>b;
        tmp = a;
        set.merge(a,b);
    }

    for(int i=1; i<=N; i++) {
        if(set.find(tmp) != set.find(i)) {
            cout<<tmp<<" "<<i<<"\n";
            break;
        }
    }
}