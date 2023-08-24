#include<bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
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
//        cout << "ans : " << endl;
        pair<int,int> p = {year, month};
        auto it = upper_bound(v.begin(), v.end(), p);
        it--;
        if(it >= v.begin()) {
            if(it->first == year && it->second == month)
                cout << "0 0" << "\n";
            else
                cout << it->first << " " << it->second << "\n";
        } else {
            cout << "-1 -1" << "\n";
        }
    }

}
