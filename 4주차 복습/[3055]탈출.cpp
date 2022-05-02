#include<iostream>
#include<cstring>
#include<queue>
#define INF 12345
using namespace std;

char map[51][51];
int R,C;
int start_r, start_c;
queue<pair <int, int> > water_q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[51][51];
int water_visited[51][51];

// void heightUp() {
//     bzero(visited, sizeof(visited));
//     for(int i=0; i<R; i++) {
//         for(int j=0; j<C; j++) {
//             if(map[i][j] == '*')
//             {
//                 for(int k=0; k<4; k++) {
//                     int tr = i + dy[k];
//                     int tc = j + dx[k];
//                     if(tr >= 0 && tc >= 0 && tr < R && tc < C) {
//                         if(map[tr][tc] == '.') {
//                             map_copy[tr][tc] = '*';
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     // for(int i=0; i<R; i++) {
//     //     for(int j=0; j<C; j++) {
//     //         map[i][j] = map_copy[i][j];
//     //     }
//     // }
//     copy(&map_copy[0][0], &map_copy[0][0] + R*C, &map[0][0]);
// }

void heightUp(int w_r, int w_c) {
    queue<pair <int, int> > q;
    q.push(make_pair(w_r, w_c));
    water_visited[w_r][w_c] = 0;
    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int dr = r+dy[i];
            int dc = c+dx[i];
            if(dr>=0 && dr<R && dc>=0 && dc<C) {
                if(map[dr][dc] == '.') {
                    if(water_visited[dr][dc] > water_visited[r][c] + 1){
                        water_visited[dr][dc] = water_visited[r][c] + 1;
                        q.push(make_pair(dr,dc));
                    }
                    
                }
            }
        }
    }
}

int logic(int s_r, int s_c) {
    int t = 0;
    queue< pair< pair<int, int>, int> > q;
    q.push(make_pair(make_pair(s_r, s_c), t));
    visited[s_r][s_c] = true;
    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int time = q.front().second;
        if(map[r][c] == 'D') return time;
        q.pop();
        for(int i=0; i<4; i++) {
            int dr = r+dy[i];
            int dc = c+dx[i];
            if(dr>=0 && dr<R && dc>=0 && dc<C && visited[dr][dc] == false) {
                if(map[dr][dc] != 'X' && water_visited[dr][dc] > time+1)
                {   
                    q.push(make_pair(make_pair(dr,dc), time+1));
                    visited[dr][dc] = true;
                }
            }
        }
    }
    return -1;
}

int main() {
    int w_r, w_c;
    cin>>R>>C;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin>>map[i][j];
            if(map[i][j] == 'S') {
                start_r = i;
                start_c = j;
            }
            // if(map[i][j] == '*') {
            //     water_q.push(make_pair(i,j));
            // }
        }
    }
    memset(water_visited, INF, sizeof(water_visited));
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            if(map[i][j] == '*') heightUp(i,j);
        }
    }
    int res = logic(start_r, start_c);
    if(res == -1) cout<<"KAKTUS"<<"\n";
    else cout<<res<<"\n";
    // for(int i=0; i<R; i++) {
    //     for(int j=0; j<C; j++) {
    //         cout<<visited[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // for(int i=0; i<R; i++) {
    //     for(int j=0; j<C; j++) {
    //         cout<<water_visited[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

}