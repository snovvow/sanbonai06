#include<iostream>
#define MAX 100001
#define INF 2147483647
using namespace std;

int N;
long long arr[MAX];
long long result[2];

void logic() {

    int start = 0;
    int end = N-1;
    long long sum;
    long long tmp = INF;
    while(start<end) {
        sum = arr[start] + arr[end];
        if (abs(sum) < abs(tmp)) {
            tmp = sum;
            result[0] = arr[start];
            result[1] = arr[end];
        }
        if (sum == 0) return;
        if (sum > 0) end--;
        else if (sum < 0) start++;

    }
}

int main() {
    cin>>N;
    for(int i=0; i<N; i++) {
        cin>>arr[i];
    }
    logic();
    cout<<result[0]<<" "<<result[1]<<"\n";
}
