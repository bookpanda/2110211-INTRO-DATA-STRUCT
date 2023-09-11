#include<bits/stdc++.h>

using namespace std;

set<pair<int,int> > s;
unordered_map<int,int> mp;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m;

    cin >> n >> m;

    while(n--) {
        int a;
        cin >> a;
        s.insert(make_pair(0,a));
        mp[a] = 0;
    }

    while(m--) {
        int comm;
        cin >> comm;
        if(comm == 1) {
            int a,b;
            cin >> a >> b;
            if(mp.find(a) == mp.end()) continue;
            s.erase(make_pair(mp[a],a));
            mp[a] += b;
            s.insert(make_pair(mp[a],a));
        } else if(comm == 2){
            int k;
            cin >> k;
            auto it = s.lower_bound(make_pair(k,-1));

            // for(auto x: s) {
            //     cout <<"(" << x.first << ", " << x.second << ")";
            // } cout << "\n";
            if(it == s.begin()) {
                cout << "NONE\n";
            } else {
                it--;
                if(it->first == 0) {
                    cout << "NONE\n";
                } else {
                    cout << it->second << "\n";
                }
            }
        }
    }
    
}