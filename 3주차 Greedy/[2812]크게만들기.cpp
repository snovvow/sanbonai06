#include<iostream>
#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;

int cash[500000];

int main(){
    int N, K;
    cin>>N>>K;
    queue<int> ipt;
    for(int i=0; i<N; i++) {
        int a;
        scanf("%1d", &a);
        ipt.push(a);
    }
    cash[0] = ipt.front();
    ipt.pop();
    int top = 1;
    int des = 0;
    while(!ipt.empty()){
        int t = ipt.front();
        while(top > 0 && des < K && cash[top-1] < t) {
            top--;
            des++;
        }   
        cash[top] = t;
        ipt.pop();
        top++;
    }
    for(int i=0; i<N-K; i++) {
        cout<<cash[i];
    }
}