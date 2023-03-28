#include<iostream>
#include<vector>
#include<cstring>
#define MAX 1000001
#define MOD 1000000009
using namespace std;

int N;
long long int dp[MAX];

void init() {
    memset(dp, -1, sizeof(dp));
}

/*
앞의 숫자를 나타내는 방법 + 1,2,3의 방법의 개수
*/
int logic(int a) {
    if (a==1) return 1;
    if (a==2) return 2;
    if (a==3) return 4;
    if (dp[a] != -1) return dp[a]%MOD;

    return dp[a]=((logic(a-3)%MOD + logic(a-2)%MOD)%MOD + logic(a-1)%MOD)%MOD;
}

int main() {
    init();
    cin>>N;
    for(int i=0; i<N; i++) {
        int a;
        cin>>a;
        cout<<logic(a)%MOD<<"\n";
    }
    
}