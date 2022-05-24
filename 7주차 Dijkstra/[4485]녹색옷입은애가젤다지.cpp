#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define INF 1324563
using namespace std;

int cost[126][126];
// int check[126][126];
bool visited[126][126];
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};

void init() {
    memset(cost, 0, sizeof(cost));
}

int logic(int num) {
    int check[num][num];
    memset(check, INF, sizeof(check));
    priority_queue<pair<int ,pair<int, int> > > q;
    q.push(make_pair(-cost[0][0],make_pair(0,0)));
    check[0][0] = cost[0][0];
    while(!q.empty()) {
        int c = -q.top().first;
        int y = q.top().second.first;
        int x = q.top().second.second; 
        q.pop();
        for(int i=0; i<4; i++) {
            int ty = y+dy[i];
            int tx = x+dx[i];
            int nextCost = cost[ty][tx] + c;
            if(ty>=0 && tx>=0 && ty<num && tx<num) {
                if(check[ty][tx] > nextCost) {
                    q.push(make_pair(-nextCost, make_pair(ty,tx)));
                    check[ty][tx] = nextCost;
                }
            }
        }
    }
    return check[num-1][num-1];
}

int main() {
    int num;
    int res = 0;
    int idx = 0;
    while(1) {
        idx++;
        init();
        cin>>num;
        if(num==0) return 0;
        for(int i=0; i<num; i++) {
            for(int j=0; j<num; j++) {
                cin>>cost[i][j];
            }
        }
        res = logic(num);
        // cout<<num<<": "<<res<<"\n";
        cout<<"Problem "<<idx<<": "<<res<<"\n"; 
    }
    return 0;
}