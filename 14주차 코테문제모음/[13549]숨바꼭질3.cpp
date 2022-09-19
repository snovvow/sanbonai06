#include<iostream>
#include<queue>
#include<vector>
#define MAX 100001
using namespace std;

int N, K;
int logic(int n, int k) {
    priority_queue<pair<int, int> > q;
    vector<long long> dist_time(MAX+1, MAX);
    q.push(make_pair(0, n));
    while(!q.empty()) {
        int t = -q.top().first;
        int d = q.top().second;
        q.pop();

        if (d == k) return t;
        if (dist_time[d] < t) continue;

        if(d*2 < MAX) {
            if(dist_time[d*2] > t) {
                q.push(make_pair(-t, d*2));
                dist_time[d*2] = t;
            }
        }
        if(d+1 < MAX) {
            if(dist_time[d+1] > t+1) {
                q.push(make_pair(-(t+1), d+1));
                dist_time[d+1] = t+1;
            } 
        }
        if(d-1 >= 0) {
            if (dist_time[d-1] > t+1) {
                q.push(make_pair(-(t+1), d-1));
                dist_time[d-1] = t+1;
            }   
        }
    }
}

int main() {
    cin>>N>>K;
    cout<<logic(N, K)<<"\n";
}