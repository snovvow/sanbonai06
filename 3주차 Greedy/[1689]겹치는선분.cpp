#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;


struct duo{
    int first, second;
};

bool cmp(duo &a, duo &b) {
        if(a.first == b.first) return a.second<b.second;
        else return a.first<b.first;
    }


vector<duo> v;
int main() {
    int N;
    cin>>N;

    duo start, end, opt;
    for(int i=0; i<N; i++) {
        int a, b;
        cin>>a>>b;
        start.first = a;
        start.second = 1;
        end.first = b;
        end.second = -1;
        v.push_back(start);
        v.push_back(end);
    }

    sort(v.begin(), v.end(), cmp);
    int m = 0;
    int res = 0;
    // while(!q.empty()) {
    //     opt = q.top();
    //     cout<<opt.first<<" "<<opt.second<<"\n";
    //     q.pop();
    // }
    for(int i=0; i<v.size(); i++) {
        opt = v[i];
        m+=opt.second;
        res = max(res, m);
    }
    cout<<res<<"\n";
}