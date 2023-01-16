#include<iostream>
#define MAX 100001
using namespace std;

int N, S;
int arr[MAX];

int logic() {
    int res = MAX;
    // for(int i=0; i<N; i++) {
    //     if (i!=0 && res >= N-i) return res;
    //     int tmp = 0;
    //     for(int j=i+1; j<N; j++) {
    //         tmp += arr[j];
    //         if(tmp >= S) {
    //             res = min(res, j-i); 
    //         }
    //     }
    // }
    int start = 0;
    int end = 0;
    int tmp = arr[0];
    while(1) {

        if (start > end || end >= N) break;
        
        if (tmp < S) {
            tmp += arr[++end];
        }
        else {
            res = min(res, end - start + 1);
            tmp -= arr[start];
            start++;
        }
    }
    return res == MAX ? 0 : res;
}

int main() {

    cin>>N>>S;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }

    cout<<logic()<<"\n";
}