#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<int> inOrder;
vector<int> postOrder;
vector<int> preOrder;

/* 
    inOrder => L Root R
    preOder => L R Root
*/

void logic(int inOrderStart, int inOrderEnd, int postOrderStart, int postOrderEnd) {
    if (inOrderStart > inOrderEnd || postOrderStart > postOrderEnd) return;

    int root = postOrder[postOrderEnd];
    int idx = find(inOrder.begin(), inOrder.end(), root) - inOrder.begin(); 
    int leftCount = idx - inOrderStart;

    preOrder.push_back(root);

    // left
    logic(inOrderStart, idx-1, postOrderStart, postOrderStart+leftCount-1);
    // right
    logic(inOrderStart+leftCount+1, inOrderEnd, postOrderStart+leftCount, postOrderEnd -1);
    
}

int main () {
    cin>>N;
    for(int i=0; i<N; i++) {
        int a;
        cin>>a;
        inOrder.push_back(a);
    }

    for(int i=0; i<N; i++) {
        int a;
        cin>>a;
        postOrder.push_back(a);
    }
    logic(0, N-1, 0, N-1);
    for(int i=0; i<preOrder.size(); i++) {
        cout<<preOrder[i]<<" ";
    }
}
