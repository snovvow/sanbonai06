#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 1e9
using namespace std;

int dp[51][51];
string input;

void init() {
    memset(dp, -1, sizeof(dp));
}

void swap(char &a, char &b) {
    char tmp = a;
    a = b;
    b = tmp;
}

// int solve(int left, int right) {
//     if(left >= right) return 0;
//     if(dp[left][right] != -1) return dp[left][right];
//     dp[left][right] = min({solve(left+1, right) + 1, solve(left, right-1) + 1, solve(left+1, right-1) + (input[left] != input[right])});

//     return dp[left][right];
// }

int solve(int left, int right) {
    if(left >= right) return 0;
    if(dp[left][right] != -1) return dp[left][right];

    dp[left][right] = INF;
    if(input[left] == input[right]) dp[left][right] = solve(left+1, right-1);
    else {       
        dp[left][right] = min({solve(left+1, right)+1, solve(left, right-1)+1, solve(left+1, right-1)+1});
    }

    return dp[left][right];
}

int main() {
    cin>>input;
    init();
    int ret = solve(0, input.length() -1);
    for(int i=0; i<input.length(); i++) {
        for(int j=i+1; j<input.length(); j++) {
            init();
            swap(input[i], input[j]);
            ret = min(ret, solve(0, input.length()-1) + 1);
            swap(input[i], input[j]);
        }
    }
    cout<<ret<<"\n";
} 