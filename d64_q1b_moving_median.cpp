#include<bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,w;
    queue<int> q;
    vector<int> v;
    vector<int> med;
    vector<int> ans;

    cin >> n >> w;

    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for(int i=0;i<w;i++) {
        med.push_back(v[i]);
        q.push(v[i]);
    }
    sort(med.begin(), med.end());

    if(n==w) {
        cout << med[w/2] << " ";
    }
    else{
        for(int i=w;i<n;i++) {
            auto it = lower_bound(med.begin(), med.end(), v[i]);
            med.insert(it, v[i]);
    //        for(auto x: med) {
    //        cout << x << " ";
    //        }
    //        cout << endl;
            ans.push_back(med[w/2]);
            auto it2 = lower_bound(med.begin(), med.end(), q.front());
            med.erase(it2);
            q.pop();
            q.push(v[i]);
        }

        for(auto x: ans) {
            cout << x << " ";
        }
    }

}

