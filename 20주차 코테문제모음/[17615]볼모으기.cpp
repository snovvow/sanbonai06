#include<iostream>
#include<string>
#include<vector>
#define INF 1e9
using namespace std;

int N;
string s;
vector<char> v;
int r_cnt = 0;
int b_cnt = 0;

int logic(int redCnt, int blueCnt) {
    int res = min(redCnt, blueCnt);
    /*
    왼쪽에서 오른쪽으로 옮길 때의 경우
    */
   int cnt = 0;
   for(int i=v.size()-1; i>=0; i--) {
        if (v[i] == v[v.size() - 1]) cnt++;
        else break;
   }
   if (v[v.size() - 1] == 'B') res = min(res, blueCnt - cnt);
   else res = min(res, redCnt - cnt);
   cnt = 0;
   for(int i=0; i<v.size(); i++) {
        if (v[i] == v[0]) cnt++;
        else break;
   }
   if (v[0] == 'B') res = min(res, blueCnt - cnt);
   else res = min(res, redCnt - cnt);

   return res;
}

int main() {

    cin>>N;
    for(int i=0; i<N; i++) {
        char a;
        cin>>a;
        if (a == 'R') r_cnt++;
        else b_cnt++;
        v.push_back(a);
    }
    cout<<logic(r_cnt, b_cnt)<<"\n";
}