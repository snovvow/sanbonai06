#include<iostream>
#include<cstring>
#define MAX 101
#define MAX_MEMORY 10000001
using namespace std;

int activate[MAX];
int cost[MAX];
//100*100이 코스트 최대 치
int dp[MAX][10001];
int N, M;
int costOfSum;

/*
dp[앱 확인 개수][cost] = memory
*/
int logic(int i, int j) {
    if (i==0) return 0;

    if (dp[i][j] != 0) return dp[i][j];
    /*
    */
    if (j-cost[i] >= 0) return dp[i][j] = max(dp[i][j], logic(i-1, j-cost[i]) + activate[i]);
    else return dp[i][j] = max(dp[i][j], logic(i-1, j));
    // for(int k=1; k<=i; k++) {
    //     for(int l=j; l<=costOfSum; l++) {
    //         if (l - cost[k]>=0) {
    //             dp[k][l] = max(dp[k][l], logic(k-1, l-cost[k]) + activate[k]);
    //         }
    //         dp[k][l] = max(dp[k][l], logic(k-1, l));
    //     }
    // }
}

int logic2(int i, int j) {

    if (dp[i][j] != 0) return dp[i][j];

    for(int k=1; k<=i; k++) {
        for(int l=0; l<=j; l++) {
            if (l-cost[k]>=0) {
                dp[k][l] = max(dp[k][l], dp[k-1][l-cost[k]] + activate[k]);
            }
            dp[k][l] = max(dp[k][l], dp[k-1][l]);
        }
    }
    return dp[i][j];
}

int main() {
    cin>>N>>M;
    for(int i=1; i<=N; i++) {
        cin>>activate[i];
    }
    
    for(int i=1; i<=N; i++) {
        cin>>cost[i];
        costOfSum += cost[i];
    }

    for(int k=1; k<=N; k++) {
        for(int l=0; l<=costOfSum; l++) {
            if (l-cost[k]>=0) {
                dp[k][l] = max(dp[k][l], dp[k-1][l-cost[k]] + activate[k]);
            }
            dp[k][l] = max(dp[k][l], dp[k-1][l]);
        }
    }
    
    for(int i=0; i<=costOfSum; i++) {
        if (dp[N][i] >= M) {
            cout<<i<<"\n";
            break;
        }
        // cout<<logic2(N, i)<<"\n";
    }

}