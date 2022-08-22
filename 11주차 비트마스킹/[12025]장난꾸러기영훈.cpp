#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

string password;
long long K, M = 1;


int main() {
    cin>>password;
    cin>>K;
    for(int i=0; i<password.length(); i++) {
        if(password[i] == '1' || password[i] == '6') {
            password[i] = '1';
            M *= 2;
        } else if(password[i] == '2' || password[i] == '7') {
            password[i] = '2';
            M *= 2;
        }
    }
    if(K > M || K < 0) {
        cout<<-1<<" ";
    } else {
        K = K - 1;
        for(int i=password.length() - 1; i>=0; i--) {
            if(password[i] == '1') {
                if(K%2 == 1) password[i] = '6';

                K = K/2;
            } else if(password[i] == '2') {
                if(K%2 == 1) password[i] = '7';

                K = K/2;
            }    
        }   
        cout<<password<<"\n";
    }
    
    return 0;
}