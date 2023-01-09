#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define MAX 500001
#define INF 12345678
using namespace std;

int N,M,L,K;
vector<pair<int, int> > v;

int logic(int p1_x, int p2_y) {
    int res = 0;
    for (int i=0; i<K; i++) {
        if (v[i].first >= p1_x && p1_x + L >= v[i].first && v[i].second >= p2_y && p2_y + L >= v[i].second) res++;
    }
    return res;
}

int main() {
    cin>>N>>M>>L>>K;

    for(int i=0; i<K; i++) {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    int res = 0;
    for(int i=0; i<K; i++) {
        for(int j=0; j<K; j++) {
            res = max(res,logic(v[i].first, v[j].second));
        }
    }
    cout<<K-res<<"\n";
}