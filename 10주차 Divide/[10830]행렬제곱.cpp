#include<iostream>
#include<cstring>
#include<algorithm>
#define MAX 5
#define MOD 1000
using namespace std;

int N;
long long B;
long long A[MAX][MAX];
long long ans[MAX][MAX];

void mulMatrix(long long a[MAX][MAX], long long b[MAX][MAX]) {
    long long tmp[N][N];
    memset(tmp, 0, sizeof(tmp));
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            for(int k=0; k<N; k++) {
                tmp[i][j] += a[i][k] * b[k][j];
            }
            tmp[i][j] = tmp[i][j] % MOD;
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            a[i][j] = tmp[i][j];
        }
    }
}

int main() {

    cin>>N>>B;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>A[i][j];
        }
        ans[i][i] = 1;
    }
    // 단순히 제곱하는 계산은 시간초과
    // for(int i=B; i>0; i--) {
    //     mulMatrix(ans, A);
    // }
    while(B>0) {
        if (B%2==1) mulMatrix(ans,A);
        mulMatrix(A,A);
        B=B/2;
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }
}