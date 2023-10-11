#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v;
map<int, int> mp;
set<pair<int,int> > s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); 
    int n,m,sp;

    cin >> n >> m >> sp;
    int init = sp;
    while(n--) {
        int t,d;
        cin >> t >> d;
        v.push_back({t,d});
    }
    sort(v.begin(), v.end());
    // mp[0] = init;
    s.insert({init, 0});
    bool zero = true;
    for(auto x: v) {
        int t = x.first;
        int d = x.second;
        sp -= d;
        if(sp<0) sp=0;
        if(sp==0) {
            if(zero) {
            mp[t] = sp;
            s.insert({sp, t});
            zero = false;
            }
        } else {
            mp[t] = sp;
            s.insert({sp, t});
        }
    }
    // for(auto x: mp) {
    //     cout << "mp[" << x.first << ", " << x.second << "]\n";
    // }
    // for(auto x: s) {
    //     cout << "s(" << x.first << ", " << x.second << ")\n";
    // }
    while(m--) {
        // cout<<"\nans\n";
        int a,q;
        cin >> a >> q;
        if(a==1) {
            auto it = mp.upper_bound(q);
            if(it == mp.begin()){
                cout << init << "\n";
            } else {
                it--;
                cout << it->second << "\n";
            }
        } else if(a==2) {
            auto it = s.upper_bound({q,-1});
            if(it == s.end()) {
                cout << 0 << "\n"; 
            } else if(it == s.begin()){
                cout << it->second+1 << "\n";
            } else {
                it--;
                cout << it->second << "\n";
            }
        }
    }
}
