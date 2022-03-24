#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

int N, M;
int map[301][301];
int map_copy[301][301];
bool visited[301][301];
int dx[4] = {-1, 1 ,0, 0};
int dy[4] = {0, 0, -1, 1};

void find_iceberg(int x, int y) {
    visited[x][y] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    while(!q.empty()){
        int rx = q.front().first;
        int ry = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int tx = rx + dx[i];
            int ty = ry + dy[i];
            if(map[tx][ty] > 0  && !visited[tx][ty]) {
                visited[tx][ty] = true;
                q.push(make_pair(tx, ty));
            }
        }
    }
}

void print() {
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cout<<map[i][j]<<" ";
        }
        cout<<"\n";
    }
}

void heightUp() {
    for(int i=1; i<N-1; i++) {
        for(int j=1; j<M-1; j++) {
            int cnt = 0;
            for(int k=0; k<4; k++) {
                int tx = i+dx[k];
                int ty = j+dy[k];
                if(tx >= 0 && ty >= 0 && tx < N && ty < M) {
                    if(map[tx][ty] <= 0) {
                        cnt++;
                    }
                }
            }
            map_copy[i][j] = map[i][j] - cnt;
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            map[i][j] = map_copy[i][j];
        }
    }
}

int main() {
    cin>>N>>M;
    int max_height = 0;
    int max_x, max_y;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin>>map[i][j];
        }
    }
    int h = 0;
    while(1) {
        int cnt = 0;
        // cout<<"\n";
        // print();
        
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(!visited[i][j] && map[i][j] > 0) {
                    find_iceberg(i,j);
                    cnt++;
                }
            }
        }
        if(cnt > 1) {
            cout<<h<<"\n";
            break;
        }
        else if(cnt == 0) {
            cout<<0<<"\n";
            break;
        }
        memset(visited, false, sizeof(visited));
        bzero(map_copy, sizeof(map_copy));
        heightUp();
        h++;
    }
}