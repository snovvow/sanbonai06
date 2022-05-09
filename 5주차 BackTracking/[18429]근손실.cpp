#include<iostream>
#include<cstring>
#define MAX 10
using namespace std;

int N, K;
int arr[MAX];
bool visited[MAX];
int res = 0;

void logic(int cnt, int weight) {
    // N일이 충족됐을때 재귀 탈출
    if(cnt == N && weight >= 500) {
        res++;
        return;
    }    
    if(weight < 500) return;
    for(int i=1; i<=N; i++) {
        if(visited[i] != true) {
            visited[i] = true;
            logic(cnt+1, weight+arr[i]-K);
            visited[i] = false;
        }
    }

}

int main() {
    cin>>N>>K;
    for(int i=1; i<=N; i++) {
        cin>>arr[i];
    }
    logic(0, 500);
    cout<<res<<"\n";

}