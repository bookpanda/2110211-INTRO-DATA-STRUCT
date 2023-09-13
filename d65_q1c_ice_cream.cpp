#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,st;
    vector<pair<int,int> > sv;

    cin >> n >> m >> st;
    while(n--) {
        int day, r;
        cin >> day >> r;
        sv.push_back(make_pair(day, r));
    }
    sort(sv.begin(), sv.end());
    queue<pair<int,int> > q;
    for(auto x: sv) {
        q.push(x);
    }

    int rate = st;
    int sum = 0;
    for(int i=0;i<100010;i++) {
        if(!q.empty() && q.front().first == i) {
            rate = q.front().second;
            q.pop();
        }
        v.push_back(sum+rate);
        sum += rate;
        // cout << "day " << sum << "\n";
    }

    // for(int i=0;i<50;i++) {
    //     cout << "day " << i << ": " << v[i] << "\n";
    // }

    while(m--) {
        int p,sc;
        cin >> p >> sc;

        auto it = lower_bound(v.begin(), v.end(), p);
        int day = it - v.begin();

        // cout << "\nDAY : " << day << endl;
        if(day > sc) {
            int cost = v[sc];
            // cout << "SCAM, cost : " << cost << endl;
            auto it2 = lower_bound(v.begin()+sc, v.end(), p+cost);
            cout << it2 - v.begin() << " ";
        } else {
            cout << day << " ";
        }
        // cout << endl;
    }
}