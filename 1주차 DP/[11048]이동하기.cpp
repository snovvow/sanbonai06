#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int dx[2] = {1,0};
int dy[2] = {0,1};

// void logic() {
//     dp[1][1] += map[1][1];
//     queue<pair <int, int> > q;
//     q.push(pair<int,int> (1,1));
//     while(!q.empty()) {
//         int x = q.front().first;
//         int y = q.front().second;
//         q.pop();
//         for(int i=0; i<3; i++) {
//             int tx = x+dx[i];
//             int ty = y+dy[i];
//             if(tx>=1 && ty>=1 && tx<=N && ty<=M) {
//                 dp[tx][ty] = max(dp[tx][ty], dp[x][y] + map[tx][ty]);
//                 q.push(pair<int, int>(tx,ty));
//             }
//         }
//     }
// }

int main() {
    int N, M;
    cin>>N>>M;
    int map[N+1][M+1];
    int dp[N+1][M+1];
    bool visited[N+1][M+1];
    bzero(map, sizeof(map));
    bzero(dp, sizeof(dp));
    bzero(visited, sizeof(visited));
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            cin>>map[i][j];
        }
    }
    
    dp[1][1] += map[1][1];
    queue<pair <int, int> > q;
    q.push(pair<int,int> (1,1));
    visited[1][1] = true;
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<2; i++) {
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(tx>=1 && ty>=1 && tx<=N && ty<=M) {
                if(!visited[tx][ty])
                {
                    q.push(pair<int, int>(tx,ty));
                    dp[tx][ty] = dp[x][y] + map[tx][ty];
                    visited[tx][ty] = true;
                }
                else if(dp[tx][ty] < dp[x][y] + map[tx][ty]){
                    q.push(pair<int, int>(tx,ty));
                    dp[tx][ty] = dp[x][y] + map[tx][ty];
                }
            }
        }
    }
    cout<<dp[N][M]<<"\n";
}