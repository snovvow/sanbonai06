#include<iostream>
#include<vector>
#include<stack>
#include<cstring>
#define MAX 501
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int N;
int map[MAX][MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];

int dfs(int y, int x) {
    if (dp[y][x] != 0) return dp[y][x];
    dp[y][x] = 1;
    for(int i=0; i<4; i++) {
        int ty = y + dy[i];
        int tx = x + dx[i];
        if (ty>= 0 && ty<N && tx>=0 && tx<N) {
            if (map[y][x] < map[ty][tx]) {
                dp[y][x] = max(dfs(ty, tx) + 1, dp[y][x]);
            }
        }
    }
    return dp[y][x];
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>map[i][j];
        }
    }
    int res = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            res = max(res, dfs(i, j));
        }
    }
    cout<<res<<"\n";
}