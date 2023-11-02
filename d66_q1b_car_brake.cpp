#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;
set<pair<int,int> > s;
int main() {
    int n,m,k;

    cin >> n >> m >> k;
    vector<pair<int,int> > v;
    while(n--) {
        int t,d;
        cin >> t >> d;
        v.push_back({t,d});
    }
    sort(v.begin(), v.end());
    int prev = k;
    mp[0] = k;
    for(auto x: v) {
        mp[x.first] = prev - x.second;
        if(mp[x.first] <=0) {
            mp[x.first] = 0;
            break;
        }
        prev -= x.second;
    }
    for(auto x: mp) {
        s.insert({x.second, x.first});
    }
    // for(auto x: mp) {
    //     cout << "mp[" << x.first << "] = " << x.second << "\n";
    // }
    // for(auto x: s) {
    //     cout << "{" << x.first << ", " << x.second << "}\n";
    // }
    while(m--) {
        int a,q;
        cin >> a >> q;
        if(a==1) {
            auto it = mp.upper_bound(q);
            it--;
            // cout << "at time " << q << ", the speed is ";
            cout << it->second << "\n";
        } else if(a==2) {
            auto it = s.lower_bound({q,-1});
            it--;
            int timeq = it->second;
            // cout << "at speed of at least" << q << ", there are ";
            cout << timeq << "\n";
        }
    }
}