#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<unordered_set>
using namespace std;

int N, M;
vector<pair<string, int> > v;
unordered_set<string> us;

void logic(string r) {
    if (us.find(r) != us.end()) {
        us.erase(r);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;

    for(int i=0; i<N; i++) {
        string s;
        cin>>s;
        us.insert(s);
    }
    char separator = ',';
    string str_buf;
    for(int i=0; i<M; i++) {
        string s;
        cin>>s;
        istringstream iss(s);
        while (getline(iss, str_buf, separator)) {
            logic(str_buf);
        }
        cout<<us.size()<<"\n";
    }
}