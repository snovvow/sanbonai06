#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int n,k;
int cnt = 0;


/*
    vector size를 잡고가면 메모리가 초과 됨 대략 21억개면 6GB?
    그래서 찾을 때마다 벡터에 넣지 말고 카운트를 올리고
    해당 카운트 값이 원하는 값 k가 되면 바로 출력
*/
void logic(int tmp, string s) {
    if (tmp == n) {
        // v[idx].push_back(s);
        // idx++;
        cnt++;
        if (cnt == k) {
            cout<<s<<"\n";
            exit(0);
        }
        return;
    }
    if (tmp > n) {
        return;
    }

    for(int i=1; i<4; i++) {
        logic(tmp+i, s+"+"+to_string(i));
    }
}

// void print_vector(int i) {
//     if (idx <= i) {
//         cout<<"-1"<<"\n";
//         return;
//     }
//     for (const auto &item : v[i]) {
//         cout << item;
//     }
//     cout<<"\n";
// }

int main() {
    cin>>n>>k;

    logic(1, "1");
    logic(2, "2");
    logic(3, "3");
    cout<<"-1"<<"\n";
    // print_vector(k-1);
}