#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    vector<pair<int,int>> v;

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        int year, month;
        cin >> year >> month;
        v.push_back({year, month});
    }
    sort(v.begin(), v.end());

    auto comp = [](pair<int,int>& p1, pair<int,int>& p2) {
        if(p1.first==p2.first) {
            return p1.second < p2.second;
        }
        return p1.first < p2.first;
    };

    for(int i=0;i<m;i++) {
        int year, month;
        cin >> year >> month;
        pair<int,int> p = {year, month};
        auto it = lower_bound(v.begin(), v.end(), p);
        if(it != v.end()) {
            if(it->first == year && it->second == month)
                cout << "0 0" << endl;
            else
                cout << it->first << " " << it->second << endl;
        } else {
            cout << "-1 -1" << endl;
        }
    }

}
