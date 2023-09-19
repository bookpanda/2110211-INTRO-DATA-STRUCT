#include<bits/stdc++.h>
using namespace std;

int main() {
    map<int , pair<int,pair<string,string> > > mp;
    mp[1] = {112, {"a", "b"}};

    for(auto it=mp.begin(); it!= mp.end();it++) {
        cout << it->second.second.first << endl;
    }

    for(auto x:mp) {
        cout << x.second.second.first << endl;
    }

    vector<map<vector<string>,stack<int> > > x;
    for(auto y:x) {
        for(auto z:y) {
            for(auto a:z.first){
                cout << a << endl;
            }
        }
    }

    set<priority_queue<pair<bool,string> > > x2;
    for(auto y:x2) {
        while(!y.empty()) {
            cout << y.top().second;
            y.pop();
        }
    }

    queue<int> q;
   int sz = q.size();
   cout << sz << endl;
}