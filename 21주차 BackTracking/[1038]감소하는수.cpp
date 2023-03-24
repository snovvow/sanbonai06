#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;

int N;
int cnt = 0;

void logic(int phaze, int n, string s) {

    if (s.length() < phaze+1 && s.length() >= phaze) {
        cnt++;
        if (cnt == N) {
            cout<<s<<"\n";
            exit(0);
        }
    }
    else if (s.length() >= phaze+1) return;

    for (int i=0; i<n; i++) {
        logic(phaze, i, s+to_string(i));
    }
}

int main() {

    cin>>N;
    if (N == 0) {
        cout<<"0"<<"\n";
        exit(0);
    }
    for (int i=1; i<11; i++) {
        for(int j=1; j<10; j++) {
            logic(i, j, to_string(j));
        }
    }
    cout<<"-1"<<"\n";
}