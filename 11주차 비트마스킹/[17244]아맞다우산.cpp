#include<iostream>
#include<queue>
#define MAX 51
using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int N,M;
char arr[5] = {'0', '1', '2', '3', '4'};
char map[MAX][MAX];
bool visit[MAX][MAX][35];
int cnt = 0;
int totalBit = 1;

int BFS(int start_y, int start_x) {
    queue<pair<pair<int, int>, pair<int,int> > > q;
    q.push(make_pair(make_pair(start_y, start_x), make_pair(0,0)));
    visit[start_y][start_x][0] = true;

    while(!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int b = q.front().second.first;
        int c = q.front().second.second;
        q.pop();
        if(map[y][x] == 'E' && b == totalBit-1) {
            return c;
        }
        for(int i=0; i<4; i++) {
            int ty = y+dy[i];
            int tx = x+dx[i];
            if(ty < M && ty >=0 && tx < N && tx >=0) {
                if('0'<=map[ty][tx] && map[ty][tx] < '5') {
                    int tb = b | 1 << map[ty][tx] - '0';
                    if(visit[ty][tx][b] == false) {
                        visit[ty][tx][b] = true;
                        q.push(make_pair(make_pair(ty, tx), make_pair(tb, c+1)));
                    }
                } else if(map[ty][tx] == '.' || map[ty][tx] == 'E' || map[ty][tx] == 'S') {
                    if(visit[ty][tx][b] == false) {
                        visit[ty][tx][b] = true;
                        q.push(make_pair(make_pair(ty, tx), make_pair(b, c+1)));
                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    cin>>N>>M;
    int s_y, s_x;
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            cin>>map[i][j];
            if(map[i][j] == 'X') {
                map[i][j] = arr[cnt];
                cnt++;
                totalBit *= 2;
            } else if(map[i][j] == 'S') {
                s_y = i;
                s_x = j;
            }
        }
    }
    int result = BFS(s_y, s_x);
    cout<<result<<"\n";
}