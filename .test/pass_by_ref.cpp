#include<bits/stdc++.h>
using namespace std;

int main() {
    queue<vector<int> > q;
    set<vector<int> > s;

    // vector<int> a;
    // a.push_back(1);
    s.insert({1});

    for(auto &x:s){
        q.push(x);
    }
    q.front()[0] = 3;

    // cout << a[0] << endl;
    // cout << a.size() << endl;
    cout << q.front()[0] << endl;

    int b = 1122;
    // a.push_back(b);
}