#include<iostream>
#include<cstring>
#define MAX 1000
using namespace std;

string s;
int a_cnt = 0;
int min_b_cnt = MAX;
int main() {
    cin>>s;
    for(int i=0; i<s.length(); i++) {
        if (s[i] == 'a') a_cnt++;
    }
    for (int i=0; i<s.length(); i++) {
        int b_cnt = 0;
        for (int j=i; j< i + a_cnt; j++) {
            if (j >= s.length()) {
                if (s[j-s.length()] == 'b') b_cnt++;
            }
            else if (s[j] == 'b') b_cnt++;
        }
        min_b_cnt = min(min_b_cnt, b_cnt);
    }
    cout<<min_b_cnt<<"\n";
}