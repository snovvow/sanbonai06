#include<iostream>
#include<cstring>
#define MAX 1000001
using namespace std;
int n, k;
int v[100];
int dp[10001];

int logic() {
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=k; j++) {
            if(v[i] <= j) {
                dp[j] = dp[j] + dp[j-v[i]]; 
            }
        }
    }
    return dp[k];
}

int main() {
    cin>>n>>k;
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    cout<<logic()<<"\n";
}