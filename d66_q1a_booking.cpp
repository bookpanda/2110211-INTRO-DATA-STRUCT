#include<bits/stdc++.h>
using namespace std;

set<pair<string, string> > s;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m;

    cin >> n >> m;

    while(n--) {
        string flight, seat;
        cin >> flight >> seat;
        s.insert({flight, seat});
    }
    while(m--) {
        int amou;
        bool success = true;
        vector<pair<string,string> > v;
        cin >> amou;
        while(amou--) {
            string flight, seat;
            cin >> flight >> seat;
            if(s.find({flight, seat}) != s.end()) {
                v.push_back({flight, seat});
            } else {
                success = false;
            }
        }
        if(success) {
            for(auto x: v){
                s.erase(x);
            }
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}