#include<iostream>
#include<cstring>
#include<vector>
#define INF 1234567
using namespace std;

int N,D;
// int shortCut[10001][10001];
vector<pair <int, int> >shortCut[10001];    //(출발지, 거리)
int dist[10001];

void logic() {
    for(int i=1; i<=D; i++) {
        if(shortCut[i].size() == 0) {
            dist[i] = dist[i-1] + 1;
        }
        else {
            for(int j=0; j<shortCut[i].size(); j++) {
                dist[i] = min(dist[i], min(dist[i-1] + 1, shortCut[i][j].second + dist[shortCut[i][j].first]));
            }
        }
    }
}

int main() {
    cin>>N>>D;
    for(int i=0; i<N; i++) {
        int a, b, c;
        cin>>a>>b>>c;
        shortCut[b].push_back(make_pair(a,c));
        // if(shortCut[a][b]!=0) shortCut[a][b] = min(shortCut[a][b], c);
        // else shortCut[a][b] = c;
    }
    for(int i=1; i<=D; i++) {
        dist[i] = INF;
    }
    logic();
    cout<<dist[D];
}