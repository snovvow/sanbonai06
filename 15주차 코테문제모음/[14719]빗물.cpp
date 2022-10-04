#include<iostream>
#define MAX 501
using namespace std;

int H, W;
int height[MAX];

int total_water() {

    int res = 0;
    for(int i=0; i<W; i++) {
        int left_max_height = 0;
        int right_max_height = 0;
        for (int j = 0; j<i; j++) {
            left_max_height = max(left_max_height, height[j]);
        }
        for (int k = i+1; k<W; k++) {
            right_max_height = max(right_max_height, height[k]);
        }
        int tmp = min(left_max_height, right_max_height) - height[i];
        if (tmp > 0) {
            res += tmp;
        }
    }
    return res;
}

int main() {
    cin>>H>>W;
    int res = 0;
    for(int i=0; i<W; i++) {
        cin>>height[i];
    }
    cout<<total_water()<<"\n";
}