#include<iostream>
#include<cstring>
using namespace std;
int N;
int s[301];
int dp[301];

// int max(int a, int b) {
//     if(a<=b) {
//         return b;
//     }
//     return a;
// }

void logic() {
    dp[0] = 0;
    dp[1] = s[1];
    dp[2] = s[1] + s[2];
    for(int i=3; i<=N; i++) {
        dp[i] = max(dp[i-2] + s[i], dp[i-3] + s[i-1] + s[i]);
    }
}

int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>s[i];
    }
    logic();
    cout<<dp[N]<<"\n";
}