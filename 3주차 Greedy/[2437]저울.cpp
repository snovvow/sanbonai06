#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    int ipt[N];
    for(int i=0; i<N; i++) {
        cin>>ipt[i];
    }
    sort(ipt, ipt+N);
    // for(int i=0; i<N; i++) {
    //     cout<<ipt[i]<<"\n";
    // }
    int sum = 0;
    if(ipt[0] != 1) {
        cout<<1<<"\n";
    }
    else {
        sum = 1;
        for(int i=1; i<N; i++) {
            if(ipt[i] > sum+1) {
                break;
            }
            sum+=ipt[i];
        }
        cout<<sum+1<<"\n";
    }
    

}