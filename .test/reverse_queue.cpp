#include<bits/stdc++.h>
using namespace std;

int main() {
    queue<int> q;
    set<pair<int,int> > s;

    for(int i=0;i<5;i++)
        q.push(i);

    while(!q.empty()) {
        s.insert({-s.size(), q.front()});
        q.pop();
    }
    for(auto &x:s){
        q.push(x.second);
    }

    while(!q.empty()) {
        cout << q.front() << endl;
        q.front() += 3;
        q.pop();
    }

    for(auto &x:s){
        cout << "{" << x.first << ", " << x.second << "}\n";
    }

}