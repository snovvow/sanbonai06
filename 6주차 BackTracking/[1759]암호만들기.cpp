#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int L,C;
vector<char> v;
string result;
int cnt_m = 0;
int cnt_z = 0;
void logic(int start, string str, int m, int z) {
    if(str.size() == L && (m >= 1 && z>= 2)) {
        cout<<str<<"\n";
        return;
    }
    for(int i = start; i<v.size(); i++) {
        if(v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u'){
            logic(i+1, str + v[i] , m+1, z);
        }
        else {
            logic(i+1, str + v[i], m, z+1);
        }
    }
}

int main() {
    cin>>L>>C;
    char a;
    for(int i=0; i<C; i++) {
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    logic(0, result, cnt_m, cnt_z);
}