#include<iostream>
#include<cstring>
#define MOD 1000000000
using namespace std;

int N,K;
int dp[201][201];
int main() {
    cin>>N>>K;

    for(int i=0; i<=N; i++) {
        dp[1][i] = 1;
    }
    for(int i=1; i<=K; i++) {
        for(int j=0; j<=N; j++) {
            for(int l=0; l<=j; l++) {
                dp[i][j] = dp[i][j]%MOD + dp[i-1][j-l]%MOD;
            }
        }
    }
    cout<<dp[K][N]%MOD<<"\n";
}
