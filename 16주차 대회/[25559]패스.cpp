#include<iostream>
#define MAX 1000001
using namespace std;

int N;
int result[MAX];
int main() {
    cin>>N;
    if (N % 2 == 1 && N!=1) {
        cout<<"-1"<<"\n";
        return 0;
    }
    for(int i=0;i<N;i++) {
        if (i%2==0) {
            cout<<N-i<<" ";
        } else {
            cout<<i<<" ";
        }
    }
}