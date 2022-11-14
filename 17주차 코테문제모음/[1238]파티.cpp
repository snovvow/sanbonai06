#include<iostream>
#include<queue>
#include<vector>
#define INF 1e9
using namespace std;

int N,M,X;
vector <pair<int ,int> > adj[1001];

int logic(int src, int destination) {
    vector<int>dist(N+1, INF);
    dist[src] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0,src));
    while(!pq.empty()){
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<adj[here].size(); i++) {
            int nextDist = cost + adj[here][i].second;
            int there = adj[here][i].first;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist[destination];
}


int main() {
    cin>>N>>M>>X;
    for(int i=0; i<M; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
    }

    int res = 0;
    for(int i=1; i<=N; i++) {
        res = max(res,logic(i,X) + logic(X,i));
    }
    cout<<res<<"\n";
}