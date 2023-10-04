#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,r;
    vector<pair<int,int> > v;
    vector<int> qs;

    cin >> n >> m >> r;
    while(n--) {
        int d, s;
        cin >> d >> s;
        v.push_back({d, s});
    }
    sort(v.begin(), v.end());
    int idx=0;
    for(int i=0;i<=100112;i++) {
        if(v.size()>0 && v[idx].first == i) {
            r = v[idx].second;
            idx++;
        }
        if(i>0)
            qs.push_back(qs.back()+r);
        else
            qs.push_back(r);
    }

    while(m--) {
        int price, scam;
        cin >> price >> scam;
        auto it1 = lower_bound(qs.begin(), qs.end(), price);
        int idx = it1 - qs.begin();
        if(idx <= scam) {
            cout << idx << " ";
        } else {
            int saved = qs[scam];
            auto it2 = lower_bound(qs.begin(), qs.end(), price + saved);
            int idx2 = it2 - qs.begin();
            cout << idx2 << " ";
        }

    }

    // for(auto x: qs) {
    //     cout << x << " ";
    // }
}