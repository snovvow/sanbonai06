#include<iostream>
#include<cstring>
#define MAX 1500001
using namespace std;

int N;
int T[MAX];
int P[MAX];
long long dp[MAX];
int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>T[i]>>P[i];
    }

    // for(int i=N; i>=1; i--) {
    //     if(i+T[i]-1 > N) {
    //         dp[i] = dp[i+1];
    //     }
    //     else {
    //         dp[i] = max(dp[i+1], dp[i+T[i]] + P[i]);
    //     }
    // }

    long long total = 0;
    for(int i=1; i<=N+1; i++) {
        total = max(total, dp[i]);
        if(i + T[i]-1 <= N) {
            // dp[i] = max(dp[i-1], dp[i]);
            if(dp[i+T[i]] <= total + P[i]) {
                dp[i+T[i]] = total + P[i];
            }
        }
        else {
            dp[i] = total;
        }
        // cout<<total<<"\n";
    }
    cout<<dp[N+1]<<"\n";
}