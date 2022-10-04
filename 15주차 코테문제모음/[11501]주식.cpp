#include<iostream>
#include<cstring>
#define MAX 1000001
using namespace std;

int T, N;
int price[MAX];
int dp[MAX];

long long logic(int day) {
    int max_price = 0;
    long long res = 0;
    for(int i=day-1; i>=0; i--) {
        if (price[i] > max_price) {
            max_price = price[i];
        }
        else if (price[i] < max_price) {
            res += max_price - price[i];
        }
    }
    return res;
}

int main() {
    cin>>T;
    for(int i=0; i<T; i++) {
        cin>>N;
        memset(price, 0, N);
        for(int j=0; j<N; j++) {
            cin>>price[j];
        }
        cout<<logic(N)<<"\n";
    }
}