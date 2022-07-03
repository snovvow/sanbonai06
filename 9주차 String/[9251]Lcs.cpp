#include<iostream>
#include<string>
#define MAX 1001
using namespace std;

int dp[MAX][MAX];
int main() {
    string a, b;
    cin>>a;
    cin>>b;

    for(int i=1; i<=a.length(); i++) {
        for(int j=1; j<=b.length(); j++) {

            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    cout<<dp[a.length()][b.length()]<<"\n";
}