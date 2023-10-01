#include<bits/stdc++.h>
using namespace std;

map<int,int> p;
map<int, set<int> > s;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;

    cin >> n >> m;
    while(n--) {
        int a;
        cin >> a;
        p[a] = 0;
        s[0].insert(a);
    }
    while(m--) {
        int comm;
        cin >> comm;
        if(comm == 1) {
            int id, amou;
            cin >> id >> amou;
            if(p.find(id) != p.end()) {
                s[p[id]].erase(id);
                if(s[p[id]].size() == 0)
                    s.erase(p[id]);
                p[id] += amou;
                if(s.find(p[id]) == s.end())
                    s[p[id]] = {};
                s[p[id]].insert(id);
            }
        } else if(comm == 2) {
            int k;
            cin >> k;
            auto it = s.lower_bound(k);
            // cout << "\nANS: \n";
            // for(auto x: s) {
            //     cout << x.first << " : ";
            //     for(auto y: x.second) {
            //         cout << y << ", ";
            //     } cout << "\n";
            // }
            if(it == s.begin()) {
                cout << "NONE\n";
                continue;
            }
            it--; //begin??
            if(it->first == 0) {
                cout << "NONE\n";
            } else cout << (*it->second.rbegin()) << "\n";
            // if(it != s.end()) {

            // }
        }
    }
}