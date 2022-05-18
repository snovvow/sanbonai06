#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#define INF 11134141515
using namespace std;

int N;
char ies[10];
long long mxn = 0;
long long mnn = INF;
bool visited[10];

void logic(int idx, long long tmp) {
    if(idx == N) {
        mxn = max(mxn, tmp);
        mnn = min(mnn, tmp);
        return;
    }
    else {
        if(ies[idx] == '<') {
            int t = tmp%10;
            for(int i=0; i<10; i++) {
                if(i > t && visited[i] == false) {
                    visited[i] = true;
                    logic(idx+1, tmp*10 + i);
                    visited[i] = false;
                }
            }
        }   
        else if(ies[idx] == '>') {
            int t = tmp%10;
            for(int i=0; i<10; i++) {
                if(i < t && visited[i] == false) {
                    visited[i] = true;
                    logic(idx+1, tmp*10 + i);
                    visited[i] = false;
                }
            }
        }
    }
    return;
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>ies[i];
    }
    for(int i=0; i<10; i++) {
        visited[i] = true;
        logic(0, i);
        visited[i] = false;
    }
    int p = pow(10,N);
    queue<int>maxq;
    queue<int>minq;

    if(mxn/p == 0) {
        maxq.push(0);
        p = p/10;
        while(p > 0){
            int a = mxn / p;
            maxq.push(a);
            mxn = mxn - a*p;
            p = p/10;
        }
    }
    else {
        cout<<mxn<<"\n";
    }

    if(mnn/p == 0) {
        minq.push(0);
        p = p/10;
        while(p > 0){
            int a = mnn / p;
            minq.push(a);
            mnn = mnn - a*p;
            p = p/10;
        }
        while(!minq.empty()) {
            cout<<minq.front();
            minq.pop();
        }
    }
    else {
        cout<<mnn<<"\n";
    }

}