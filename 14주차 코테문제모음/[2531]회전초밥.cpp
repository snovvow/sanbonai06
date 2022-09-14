#include<iostream>
#include<vector>
#include<cstring>
#define MAX 40000
using namespace std;

int N, d, k, c;
vector<int> v;
bool check[MAX];
// set<int> s;
// set<int>:: iterator iter;

// int logic(int idx) {

//     int coupon = 1;
//     set<int> s;
//     s.clear();
//     int cnt = 0;
//     for(int i=idx; i<idx+k; i++) {
//         int k = 0;
//         if (i >= v.size()) k = i - v.size();
//         else k = i;

//         if (s.find(v[i]) != s.end() || (s.find(v[i]) == s.end() && *s.end() == v[i])) cnt++;
//         s.insert(v[i]);
//     }
//     if (s.find(c) != s.end() || (s.find(c) == s.end() && *s.end() == c)) coupon = 0;
//     return k - cnt + coupon;
// }

int main() {

    cin>>N>>d>>k>>c;
    for(int i=0; i<N; i++) {
        int a; 
        cin>>a;
        v.push_back(a);
    }
    int res = 0;
    for(int i=0; i<N; i++) {
        int cnt = 0;
        int bonus = 1;
        memset(check, false, sizeof(check));
        for (int j = i; j<i+k; j++) {
            if (check[v[j%N]] == true) cnt++;
            else check[v[j%N]] = true;

            if (v[j%N] == c) bonus = 0;
        }
        res = max(res, k - cnt + bonus);
    }
    cout<<res<<"\n";
}