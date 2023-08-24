#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    vector<pair<int,int>> v;
    vector<int> va;
    map<int, int> type;

    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(), v.end());
    for(auto x: v) {
        va.push_back(x.first);
        va.push_back(x.second);
//        cout << x.first << x.second;
        type[x.first] = 1;
        type[x.second] = -1;
    }
    auto comp = [](pair<int,int> &p, int value) {
        return p.first < value;
    };
    for(int i=0;i<m;i++) {
        int a;
        cin >> a;
//        auto it = lower_bound(v.begin(), v.end(), a, comp);
        auto it = lower_bound(va.begin(), va.end(), a);
//        cout << "it = " << it->first << " " << it->second << endl;
        cout << "it = " <<  *it << endl;
        if(it == va.end()) {
            cout << 0 << " ";
        }
        else if(*it > a) {
            cout << 0 << " ";
        } else {
            cout << 1 << " ";
        }
//        if(type[*it] == -1 || (type[*it] ==1 && *it == a)) {
//        } else {
//        }
    }
}
