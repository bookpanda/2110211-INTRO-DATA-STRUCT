#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;

    // for(int i=0;i<n;i++) {}
    while(n--) {}

    set<pair<int,int> > s;
    s.insert({1,2});
    queue<int> q;
    while(!q.empty()) {
        // desc sorting
        // s.insert({-1*s.size(), q.front()});
        s.insert({-s.size(), q.front()});
        q.pop();
    }

    // for(auto x:s) {}
    for(auto &x:s){
        cout << "{" << x.first << ", " << x.second << "}\n";
    }

    // vector<pair<int,pair<int,int > > > v;
    vector<vector<int> > v;

    set<vector<int> > s2;
    // vector<int> a;
    // a.push_back(1);
    // s.insert(a);
    s2.insert({1});
}