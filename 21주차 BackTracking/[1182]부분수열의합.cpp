#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, S;
vector<int> v;
int res = 0;

void logic(int idx, int tmp) {
    //탈출조건
    if (tmp == S) {
        res++;
    } else if (v[idx]>0 && tmp+v[idx+1]>S) {
        return;
    } else if (idx >= v.size()) return;

    for(int i=1; i<v.size()-idx; i++) {
        logic(idx+i, tmp+v[idx+i]);
    }
}

int main() {
    cin>>N>>S;

    for(int i=0; i<N; i++) {
        int a;
        cin>>a;
        v.push_back(a);
    }
    /*
    억울하다... 무조건 정렬되어서 나오는 줄 알았다/
    */
    sort(v.begin(), v.end());
    for (int i=0; i<v.size(); i++) {
        logic(i, v[i]);
    }
    cout<<res<<"\n";
}