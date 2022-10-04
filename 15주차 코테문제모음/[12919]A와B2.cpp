#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

vector<char> s;
vector<char> t;
void logic(vector<char> v) {
    if (v.size() == s.size()) {
        if (equal(v.begin(), v.end(), s.begin())) {
            cout<<"1"<<"\n";
            exit(0);
        }
        return;
    }
    if (v.size() < s.size()) return;
    // v.push_back('A');
    // logic(v);
    // v.pop_back();
    // v.push_back('B');
    // reverse(v.begin(), v.end());  
    // logic(v);
    // reverse(v.begin(), v.end());
    // v.pop_back();
    if(*(v.end()-1) == 'A') {
        v.erase(v.end() - 1);
        logic(v);
        v.push_back('A');
    } 
    if(v[0] == 'B') {
        v.erase(v.begin());
        reverse(v.begin(), v.end());
        logic(v);
        v.push_back('B');
        reverse(v.begin(), v.end());
    }

    return;
}

int main() {

    string S, T;
    vector<char> v;
    cin>>S>>T;
    for(int i=0; i<S.length(); i++) {
        s.push_back(S[i]);
    }
    for(int i=0; i<T.length(); i++) {
        t.push_back(T[i]);
    }
    logic(t);
    cout<<"0"<<"\n";
}