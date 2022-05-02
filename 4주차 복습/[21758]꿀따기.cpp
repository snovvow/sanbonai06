#include<iostream>
#define MAX 100001
using namespace std;

int list[MAX];
int N;
long long prefix_sum[MAX];

void init() {
    prefix_sum[1] = list[1];
    for(int i=2; i<=N; i++) {
        prefix_sum[i] = prefix_sum[i-1] + list[i];
    }
}

long long logic() {
    long long result = 0;
    //벌통이 왼쪽 끝
    for(int i = 2; i<N; i++) {
        result = max(result, prefix_sum[i-1] + prefix_sum[N-1] - list[i]);
    }
    //벌통이 오른쪽 끝
    for(int i = 2; i<N; i++) {
        result = max(result, prefix_sum[N] - prefix_sum[i] + prefix_sum[N] - prefix_sum[1] - list[i]);
    }
    //예외
    for(int i=2; i<N; i++) {
        result = max(result, prefix_sum[i] - prefix_sum[1] + prefix_sum[N-1] - prefix_sum[i] + list[i]);
    }
    return result;
}

int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>list[i];
    }
    init();
    cout<<logic()<<"\n";
}