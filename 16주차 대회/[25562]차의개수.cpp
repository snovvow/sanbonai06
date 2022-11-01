#include<iostream>
using namespace std;

int N;

int main() {
    cin>>N;
    cout<< N * (N-1) / 2<<"\n";
    int result=1;

    for(int i=0; i<N-1; i++) {
        cout<<result<<" ";
        result = result * 2;
    }
    cout<<result<<"\n"; //WHY?
    cout<<N-1<<"\n";
    for(int i=0; i<N; i++) {
        cout<<result<<" ";
        result += 1;
    }
}