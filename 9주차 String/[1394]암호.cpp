#include<iostream>
#include<cstring>
#define MOD 900528
#define MAX 1000000
using namespace std;

string base;
string password;
int t[MAX];
long long res;

int main() {
    cin>>base;
    cin>>password;
    long long l = base.length();
    for(int i=0; i<password.length(); i++) {
        t[i] = base.find(password[i]) + 1;
    }

    long long ret = t[0];
    for(int i=1; i<password.length(); i++) {
        ret = (l*ret + t[i])%MOD;
    }
    cout<<ret%MOD<<"\n";
}