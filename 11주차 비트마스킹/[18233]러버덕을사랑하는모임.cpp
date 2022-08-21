#include<iostream>
#include<vector>
#include<cstring>
#define MAX 1000001
using namespace std;

int N, P, E;
int minimun[MAX];
int maximum[MAX];
int result[21];
bool flag = false;

void backTracking(int idx, vector<int> v) {
    if(flag == true) return;
    if(v.size() == P) {
        int mx = 0;
        int mn = 0;
        for(int i=0; i<v.size(); i++) {
            mn += minimun[v[i]];
            mx += maximum[v[i]];
        }
        if(mn <= E && mx >= E) {
            for(int i=0; i<v.size(); i++) {
                result[v[i]] = minimun[v[i]];
            }
            int diff = E - mn;
            for(int i=0; i<v.size(); i++) {
                int personDiff = maximum[v[i]]-minimun[v[i]];
                if(personDiff <= diff) {
                    result[v[i]] += personDiff;
                    diff = diff-personDiff;
                } else {
                    result[v[i]] += diff;
                    diff = 0;
                }
            }
            for(int i=0; i<N; i++) {
                cout<<result[i]<<" ";
            }
            flag = true;
            return;
        }
    }
    for(int i=idx+1; i<N; i++) {
        v.push_back(i);
        backTracking(i, v);
        v.pop_back();
    }
}

int main() {

    cin>>N>>P>>E;

    for(int i=0; i<N; i++) {
        cin>>minimun[i]>>maximum[i];
    }
    for(int i=0; i<N; i++) {
        vector<int> v;
        v.push_back(i);
        backTracking(i, v);
        v.pop_back();
    }
    if(flag == false) cout<<-1<<" ";
    return 0;
}
