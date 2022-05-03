#include<iostream>
#include<cstring>
#define INF 200000
using namespace std;

int ablity[21][21];
int N;
int total_ab = 0;
int min_num = INF;
int team[21];
void logic(int position, int size) {
    if(size == N/2){
        int m = 0;
        int a = 0;
        for(int j = 1; j<N; j++) {
            for(int k = j+1; k<=N; k++) {
                if(team[j]==1&&team[k]==1)
                    m+=(ablity[j][k] + ablity[k][j]);
                if(team[j]==0&&team[k]==0)
                    a+=(ablity[j][k] + ablity[k][j]);
            }
        }
        a=a-m;
        a = a>=0?a:-a;
        min_num = min(min_num, a);
        return;
    }
    // else if(position == N) {
    //     bzero(team, sizeof(team));
    //     return;
    // }
    for(int i=position; i<=N; i++) {
        team[i] = 1;
        logic(i+1, size+1);
        team[i] = 0;
    }
}
int main() {
    cin>>N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin>>ablity[i][j];
            total_ab += ablity[i][j];
        }
    }
    logic(1,0);
    cout<<min_num<<"\n";
}