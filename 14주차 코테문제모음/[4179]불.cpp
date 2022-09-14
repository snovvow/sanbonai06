#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define MAX 1001
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int R, C;
char map[MAX][MAX];
queue<pair<int, int> > f_q;
int j_y, j_x;
bool visited[MAX][MAX];
int fire_cnt[MAX][MAX];

void fire_bfs(queue<pair<int, int> > q) {
    while(!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int ty = y+dy[i];
            int tx = x+dx[i];
            if (ty>=0 && ty<R && tx>=0 && tx<C) {
                if (map[ty][tx] != '#' && fire_cnt[ty][tx] == 0) {
                    fire_cnt[ty][tx] = fire_cnt[y][x] + 1;
                    q.push(make_pair(ty, tx));
                }
            }
        }
    }
}

int bfs(int start_y, int start_x) {
    queue<pair< pair<int, int>, int > > q;
    q.push(make_pair(make_pair(start_y, start_x), 0));
    visited[start_y][start_x] = true;
    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int ty = y+dy[i];
            int tx = x+dx[i];
            if(ty < 0 || ty >= R || tx < 0 || tx >= C) {
                // cout<<ty<<" "<<tx<<" "<<"\n";
                // for(int i=0; i<R; i++) {
                //     for(int j=0; j<C; j++) {
                //         cout<<visited[i][j]<<" ";
                //     }
                //     cout<<"\n";
                // }
                return cnt+1;
            }
            else if(ty >= 0 && ty < R && tx >= 0 && tx < C) {
                if (visited[ty][tx] == false && map[ty][tx] == '.' && (cnt+1 < fire_cnt[ty][tx] || fire_cnt[ty][tx] == 0)) {
                    q.push(make_pair(make_pair(ty, tx), cnt+1));
                    visited[ty][tx] = true;
                }
            }
        }
    }
    return -1;
}

int main() {
    cin>>R>>C;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin>>map[i][j];
            if(map[i][j] == 'J') {
                j_y = i;
                j_x = j;
            } else if (map[i][j] == 'F') {
                f_q.push(make_pair(i, j));
            }
        }
    }
    fire_bfs(f_q);
    int res = bfs(j_y, j_x);
    if (res == -1) cout<<"IMPOSSIBLE"<<"\n";
    else cout<<res<<"\n";
}