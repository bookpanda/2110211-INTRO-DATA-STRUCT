#include<bits/stdc++.h>
using namespace std;

// map<int, int> mp;
int main() {
    int n,m;
    cin >> n >> m;
    vector<pair<int,int> > v(n, {0,0});

    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        if(a == 1) {
            int h = b%n;
            int add = 1;
            while(v[h].second == 1) {
                h += add;
                h %= n;
                add += 2;
            }
            v[h] = {b, 1};
        } else if(a == 2) {
            int h = b%n;
            int add = 1;
            while(v[h].second == 1 || v[h].second == 2) {
                if(v[h].first == b) {
                    break;
                }
                h += add;
                h %= n;
                add += 2;
            }
            if(v[h].second == 1) {
                v[h].second = 2;
            }
        }
        // cout << "after " << a << " " << b << "\n";
        // for(auto &x: v) {
        //     cout << x.first << "," << x.second << " ";
        // } cout << "\n";
    }

    int maxedit=0;
    for(int i=0;i<n;i++) {
        int h = i % n;
        int add = 1;
        int cou=0;
        while(v[h].second == 1) {
            h += add;
            h %= n;
            add += 2;
            cou++;
        }
        maxedit = std::max(maxedit, cou);
    }

    int maxfind=0;
    for(int i=0;i<=40000;i++) {
        int h = i % n;
        int add = 1;
        int cou=0;
        while(v[h].second == 1 || v[h].second == 2) {
            if(v[h].first == i) {
                break;
            }
            h += add;
            h %= n;
            add += 2;
            cou++;
        }
        maxfind = std::max(maxfind, cou);
    }
    cout << maxedit+1 << " " << maxfind+1 << "\n";
}