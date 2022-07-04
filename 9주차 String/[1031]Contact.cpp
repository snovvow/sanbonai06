#include<iostream>
#include<string>
#include<regex>
using namespace std;

int main() {
    int N;
    cin>>N;
    for(int i=0; i<N; i++) {
        string input;
        cin>>input;
        regex pattern("(100+1+|01)+");
        if(regex_match(input, pattern)) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
}