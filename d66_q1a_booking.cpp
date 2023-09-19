#include<bits/stdc++.h>
using namespace std;

set<pair<string,string> > s;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m;

    cin >> n >> m;
    while(n--) {
        string a, t;
        cin >> a >> t;
        s.insert({a,t});
    }
    while(m--) {
        int amou;
        vector<pair<string,string> > v;
        bool success = true;
        cin >> amou;
        while(amou--) {
            string a,t;
            cin >> a >> t;
            auto it = s.find({a,t});
            if(it!=s.end()) {
                // s.erase(it);
                v.push_back({a,t});
            } else {
                success = false;
            }
        }
        if(success) {
            cout << "YES\n";
            for(auto x: v) {
                s.erase(x);
            }
        } else {
            cout << "NO\n";
        }
    }
}