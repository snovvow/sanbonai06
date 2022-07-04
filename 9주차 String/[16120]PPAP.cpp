#include<iostream>
#include<string>
#include<queue>
#include<vector>
using namespace std;

int main() {
    string c;
    cin>>c;

    int l = c.size();
    queue<char> q;
    vector<char> v;

    for(int i=0; i<l; i++) {
        if(c[i] == 'P' && c[i+1] == 'P' && c[i+2] == 'A' && c[i+3] == 'P') {
            q.push('P');
            v.push_back('P');
            i = i + 3;
        }
        else {
            q.push(c[i]);
            v.push_back(c[i]);
        }

        if(v.size() >= 4) {
            int vl = v.size()-1;
            if(v[vl-3] == 'P' && v[vl-2] == 'P' && v[vl-1] == 'A' && v[vl] == 'P') {
                v.pop_back();
                v.pop_back();
                v.pop_back();
                v.pop_back();
                v.push_back('P');
            }

        }
    }
    if(v.size() == 0 || (v.size() == 1 && v[0] == 'P')) cout<<"PPAP"<<"\n";
    else cout<<"NP"<<"\n";
}