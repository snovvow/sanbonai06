#include<iostream>
#include<vector>
#include<cstring>
#define MAX 200001
using namespace std;
int N, K;
int arr[100001];
int map[MAX];
int main() {
    cin>>N>>K;
    for(int i=0; i<N; i++) {
        int a;
        cin>>a;
        map[i] = a;
    }
    int head = 0;
    int tail = 0;
    int res = 0;
    while(head < N) {
        if (arr[map[head]] < K) {
            arr[map[head]]++;
            head++;
        } else if (arr[map[head]] >= K) {
            arr[map[tail]]--;
            tail++;
        }
        res = max(res, head-tail);
    }
    cout<<res<<"\n";
}