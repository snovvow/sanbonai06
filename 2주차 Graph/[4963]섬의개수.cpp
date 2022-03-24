#include<iostream>
#include<cstring>
using namespace std;

int map[50][50];
bool visited[50][50];
int dx[8] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0,0,-1,1, -1, 1, -1, 1};    
int cnt = 0;

void init() {
    memset(map, 0, sizeof(map[0][0])*50*50);
    memset(visited, false, sizeof(visited[0][0])*50*50);
    
}   
void logic(int x, int y) {
    visited[x][y]=true;
    for(int i=0; i<8; i++) {
        int tx = x+dx[i];
        int ty = y+dy[i];
        if(tx >=0 && ty >=0 && tx<50 && ty<50) {
            if(map[tx][ty] == 1 && visited[tx][ty] == false) {
                visited[tx][ty] = true;
                logic(tx, ty);
            }
        }
    }
}

int main() {
    while(1) {
        int w, h;
        cin>>w>>h;
        init();
        if(w == 0 && h == 0) 
            break;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                cin>>map[i][j];
            }
        }
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(map[i][j] == 1 && visited[i][j] == false)
                {
                    ++cnt;
                    logic(i,j);
                }
            }
        }
        cout<<cnt<<"\n";
        cnt = 0;
        
    }
    return 0;
}
