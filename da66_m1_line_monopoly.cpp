#include<bits/stdc++.h>
using namespace std;

map<int,int > mp;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;

    cin >> n;
    while(n--) {
        int a;
        cin >> a;
        if(a == 1) {
            int st, ed;
            cin >> st >> ed;
            auto it = mp.upper_bound(st);
            // cout << "it = " << it->first << ", " << it->second << "\n";
            if(it == mp.begin() || mp.size() == 0) {
                // cout << "begin or sz=0" << "\n";
                mp[st] = ed;
                it = mp.find(st);
            } else {
                it--;
                // cout << "it--" << "\n";
                if(it->second+1 < st) {
                    mp[st] = ed;
                    it = mp.find(st);
                } else {
                    it->second = max(it->second, ed);
                }
            }
            auto next = it;
            next++;
            while(next!=mp.end() && it->second+1 >= next->first) { 
                it->second = max(it->second, next->second);
                auto tmp = next;
                tmp++;
                mp.erase(next);
                next = tmp;
            }

            // for(auto &x : mp) {
            //     cout << "(" << x.first << ", " << x.second << ") ";
            // } cout << "\n";
            
        } else if(a == 2) {
            cout << mp.size() << "\n";
        }
    }
}