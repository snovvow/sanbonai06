#include<iostream>
#include<vector>
using namespace std;

long long int N, K, M;

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
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int d;
    cin>>d;
    for(int i=1; i<=d; i++) {
        int a,b;
        cin>>N;
        disJoinSet set(N);
        cin>>K;
        cout<<"Scenario "<<i<<":"<<"\n";
        for(int j=0; j<K; j++) {
            cin>>a>>b;
            set.merge(a,b);
        }
        cin>>M;
        for(int k=0; k<M; k++) {
            cin>>a>>b;
            if(set.find(a) != set.find(b)) {
                cout<<"0"<<"\n";
            }
            else cout<<"1"<<"\n";
        }
        cout<<"\n";
    }
}