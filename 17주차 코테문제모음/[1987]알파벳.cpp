#include<iostream>
#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;

int R,C;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char map[20][20];
bool visited[20][20];
int cnt[20][20];
int res = 0;
bool check[26]; //false면 이미 사용 true면 미사용

void init() {
    memset(check, true, sizeof(check));
    memset(visited, 0, sizeof(visited));
}

void logic(int x, int y) {
    res = max(res, cnt[x][y]);
    for(int i = 0; i<4; i++) {
        int tx = x+dx[i];
        int ty = y+dy[i];
        if(tx>=0 && ty>=0 && tx<R && ty<C) {
            int c = map[tx][ty] - 'A';
            int d = map[tx][ty];
            if(!visited[tx][ty] && check[c]) {
                visited[tx][ty] = true;
                check[c] = false;
                cnt[tx][ty] = cnt[x][y] + 1;
                logic(tx, ty);
                check[c] = true;
                visited[tx][ty] = false;
            }
        }
    }
}

int max(int a, int b) {
    if(a>=b) {
        return a;
    }

    return b;
}

int main() {

    init();
    cin>>R>>C;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin>>map[i][j];
        }
    }
    cnt[0][0]=1;
    visited[0][0] = true;
    int d = map[0][0] - 'A';
    check[d] = false;
    logic(0,0);

    cout<<res<<"\n";

}