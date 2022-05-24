#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define INF 1e9
using namespace std;

vector<pair <int, int> >adj[5001];
int V,E,P;

long long logic(int start, int end) {
    vector<long long>dist(V+1, INF);
    dist[start] = 0;
    priority_queue<pair <int, int> >pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();
        if(dist[here] < cost) continue;
        for(int i=0; i<adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist[end];
}

int main() {
    cin>>V>>E>>P;
    for(int i=0; i<E; i++) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c));
    }
    if(logic(1, P) + logic(P, V) == logic(1, V)) {
        cout<<"SAVE HIM"<<"\n";
    }
    else cout<<"GOOD BYE"<<"\n";
}