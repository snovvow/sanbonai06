#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 2001
using namespace std;

int N;
vector<long long> v;

bool logic(int a, int left, int right) {
    if (left >= right) return false;

    if (left == a) return logic(a, left+1, right);
    if (right == a) return logic(a, left, right-1);
    if (v[left] + v[right] < v[a]) {
            return logic(a, left + 1, right);
    }
    else if (v[left] + v[right] > v[a]) {
        return logic(a, left, right - 1);
    }
    if (v[left] + v[right] == v[a]) {
        return true;
    }

    
    return false;
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        int a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    int res = 0;
    for(int i=0; i<N; i++) {
        if (logic(i, 0, N-1)) res++;
    }
    cout<<res<<"\n";
}