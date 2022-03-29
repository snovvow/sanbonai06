#include<iostream>
#include<vector>
#include<algorithm>
#define INF 1000001
using namespace std;

 
struct man {
    int score_s;
    int score_p;
};
bool cmp(struct man a, struct man b) {
    return (a.score_s<b.score_s);
}

struct man a[100001];

int logic(int p) {
    int result = 0;
    int min_num = INF;
    for(int i=0; i<p; i++) {
        if(min_num > a[i].score_p) {
            result++;
            min_num = a[i].score_p;
        }
    }
    return result;
}

int main() {
    int T;
    cin>>T;
    for(int i=0; i<T; i++) {
        int people;
        int s, p;
        cin>>people;
        for(int j=0; j<people; j++) {
            cin>>s>>p;
            a[j].score_s = s;
            a[j].score_p = p;
        }
        sort(a, a+people, cmp);
        cout<<logic(people)<<"\n";
    }
}