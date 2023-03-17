#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N, L, R;
int map[51][51];
bool visited[51][51];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void init(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            visited[i][j] = false;
        }
    }
}

int logic(int r, int c) {
    int tmp = map[r][c];
    queue<pair<int, int> > q;
    vector<pair<int , int> > v;
    v.push_back(make_pair(r,c));
    q.push(make_pair(r,c));
    visited[r][c] = true;
    while(!q.empty()) {
        int t_r = q.front().first;
        int t_c = q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int d_r = t_r + dy[i];
            int d_c = t_c + dx[i];
            if (d_r>=0 && d_r<N && d_c>=0 && d_c<N) {
                if (!visited[d_r][d_c]) {
                    int diff = abs(map[d_r][d_c] - map[t_r][t_c]);
                    if (L<=diff && diff<=R) {
                        v.push_back(make_pair(d_r,d_c));
                        q.push(make_pair(d_r,d_c));
                        visited[d_r][d_c] = true;
                        tmp += map[d_r][d_c];
                    }
                }
            }
        }
    }
    if (v.size() == 1) {
        return 0;
    } else {
        for(int i=0; i<v.size(); i++) {
            map[v[i].first][v[i].second] = tmp/v.size();
        }

        return 1;
    }
    
}

int main() {

    cin>>N>>L>>R;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin>>map[i][j];
        }
    }

    int res = 0;
    while(1) {
        int tmp = 0;
        init(N);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                if (!visited[i][j]) {
                    tmp+=logic(i, j);
                }
            }
        }
        if (tmp == 0) {
            cout<<res<<"\n";
            break;
        } else {
            res++;
        }
    }
}