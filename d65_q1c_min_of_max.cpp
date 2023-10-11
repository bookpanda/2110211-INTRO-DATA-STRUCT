#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    set<pair<int,int> > s;
    map<int, int> mp;
    vector<int> pw, type;

    cin >> n >> m;
    for(int i=0;i<m;i++) {
        mp[i] = 1;
        s.insert({1,i});
    }
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        pw.push_back(a);
    }
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        type.push_back(a);
    }
    for(int i=0;i<n;i++) {
        if(mp.find(type[i]) != mp.end()) {
            // cout << "found type\n";
            if(pw[i] > mp[type[i]]) {
                // cout << "more pw\n";
                auto it = s.find({mp[type[i]], type[i]});
                if(it != s.end()) {
                    // cout << "in set\n";
                    s.erase(it);
                    s.insert({pw[i], type[i]});
                }
                mp[type[i]] = pw[i];
            }
        }
        // for(auto x: s) {
        //     cout << "{" << x.first << ", " << x.second << "} ";
        // } cout << "\n";
        auto it = s.begin();
        cout << it->first << " ";
    }

}