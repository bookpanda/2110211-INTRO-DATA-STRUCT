#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n,m,k;
    vector<int> v;

    cin >> n >> m >> k;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    for(int i=0;i<m;i++) {
        int a;
        cin >> a;
//        cout << "look " << a-k << " to " << a+k << endl;
        auto it1 = lower_bound(v.begin(), v.end(), a-k);
        auto it2 = upper_bound(v.begin(), v.end(), a+k);
//        cout << *it1 << " " << *it2 << endl;
        cout << it2-it1 << " ";
    }

}
