#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

int N;
bool visited[101];
bool map[101][101];
int cnt = 0;
void logic(int x) {
    cnt++;
    visited[x] = 1;
    for(int i=1; i<=N; i++) {
        if(map[x][i] && !visited[i]) {
            logic(i);
        }
    }
}

int main() {
    int M;
    cin>>N;

    memset(map, false, sizeof(map));
    memset(visited, false, sizeof(visited));
    cin>>M;
    for(int i=0; i<M; i++) {
        int a, b;
        cin>>a>>b;
        map[a][b] = 1;
        map[b][a] = 1;
    }
    logic(1);
    cout<<cnt<<"\n";
}