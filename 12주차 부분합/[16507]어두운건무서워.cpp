#include<iostream>
#define MAX 1001
using namespace std;

int R,C, Q;
int map[MAX][MAX];
int r1, r2, c1, c2;
int arr[MAX][MAX];

void init(int r, int c) {
    arr[1][1] = map[1][1];
    for(int i=1; i<=r; i++) {
        for(int j=1; j<=c; j++) {
            if(i > 1 && j == 1) {
                arr[i][j] = arr[i-1][c] + map[i][j];
            }
            arr[i][j] = arr[i][j-1] + map[i][j];
        }
    }
}

int logic(int r1, int c1, int r2, int c2) {
    int totalCnt = 0;
    for(int i=r1; i<=r2; i++) {
        totalCnt += arr[i][c2] - arr[i][c1] + map[i][c1];
    }
    int totalWidth = (r2-r1+1) * (c2-c1+1);
    return totalCnt/totalWidth;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>R>>C>>Q;
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++) {
            cin>>map[i][j];
        }
    }
    init(R, C);
    for(int i=0; i<Q; i++) {
        cin>>r1>>c1>>r2>>c2;
        cout<<logic(r1, c1, r2, c2)<<"\n";
    }
    return 0;
}