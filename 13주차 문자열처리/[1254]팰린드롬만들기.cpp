#include<iostream>
#include<cstring>
using namespace std;

string s;

bool check(int start) {

    for (int i = start; i < s.length(); i++) {
        if (s[i] != s[s.length() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {

    cin>>s;
    int cnt = 0;
    for(int i=0; i<s.length(); i++) {
        cout<<"I: "<<i<<"\n";
        if (check(i)) {
            cnt = s.length() + i;
            break;
        }
    }
    for(int i=0; i<s.length(); i++) {
        cout<<s[i];
    }
    cout<<cnt<<"\n";
}