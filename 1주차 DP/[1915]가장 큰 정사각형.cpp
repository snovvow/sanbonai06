#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;

int n, m;
int map[1001][1001];
long long dp[1001][1001];
void logic() {
    for(long long i=0; i<n; i++) {
        for(long long j=0; j<m; j++) {
            if(map[i][j] == 1) {
                map[i][j] = min(map[i-1][j], min(map[i-1][j-1], map[i][j-1])) + 1;
            }
        }
    }
}

int main() {

    cin>>n>>m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    logic();
    int result = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            result = max(result, map[i][j]);
        }
    }
    cout<<result*result<<"\n";
}