#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int N;

int main() {
    cin>>N;
    vector<pair<int, int> > v;
    for(int i=0; i<N; i++) {
        int a, b;       //도착시간, 검문시간
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());

    int res = 0;
    int cash = 0;
    for(int i=0; i<N; i++) {
        if(cash > v[i].first) {
            res=cash + v[i].second;
        }
        else if(cash == v[i].first){
            res+= v[i].second;
        }
        else {
            res = v[i].first + v[i].second;
        }
        cash = res;
        // cout<<res<<" "<<cash<<"\n";
    }
    cout<<res<<"\n";
}