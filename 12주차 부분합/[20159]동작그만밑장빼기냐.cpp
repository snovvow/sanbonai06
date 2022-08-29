#include<iostream>
#define MAX 100001
using namespace std;

int N;
int card[MAX];
int my[MAX];
int opp[MAX];

int logic() {
    int result = 0;
    for(int i=1; i<=N; i++) {
        if(i%2 == 1) {
            result = max(result, my[i-1] + card[N] + opp[N-1] - opp[i-1]);
        } else {
            result = max(result, my[i-1] + opp[N-1] - opp[i-1]);
        }
    }
    return result > my[N] ? result : my[N];
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    for(int i=1; i<=N; i++) {
        cin>>card[i];
        if(i%2==1) {
            my[i] += my[i-1] + card[i];
            opp[i] = opp[i-1];
        } else {
            opp[i] += opp[i-1] + card[i];
            my[i] = my[i-1];
        }
    }
    opp[N] -= card[N];
    cout<<logic()<<"\n";
}