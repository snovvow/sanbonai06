#include<iostream>
#define MAX 50001
using namespace std;

int N;
int peopleCnt[MAX];
int maxCnt;
int arr[MAX] = {-1,};
int dp[4][MAX];

int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>peopleCnt[i];
    }
    cin>>maxCnt;
    arr[0] = peopleCnt[0];
    arr[1] = arr[0] + peopleCnt[1];
    for(int i=2; i<=N; i++) {
        arr[i] = arr[i-1] + peopleCnt[i];
    }
    for(int i=1; i<=3; i++) {
        for(int j=i*maxCnt; j<=N; j++) {
            dp[i][j] = max(dp[i][j-1], dp[i-1][j-maxCnt] + arr[j] - arr[j-maxCnt]);
        }
    }
    cout<<dp[3][N]<<"\n";
    return 0;
}