#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); 
    int n,w;
    queue<int> q;
    vector<int> v;
    q.push(-1);

    cin >> n >> w;
    if(w == n) w--;
    int k = (w)/2;
    n -= w;
    while(w--) {
        int a;
        cin >> a;
        // s.insert(a);
        v.push_back(a);
        q.push(a);
    }
    sort(v.begin(), v.end());
    while(n--) {
        int a;
        cin >> a;
        // s.insert(a);
        auto fit = lower_bound(v.begin(), v.end(), a);
        v.insert(fit, a);
        // auto it1 = s.find(q.front());

        auto it1 = lower_bound(v.begin(), v.end(), q.front());
        if(q.front() != -1 && it1 != v.end())
            v.erase(it1);
            // s.erase(it1);
        q.push(a);
        q.pop();
        // cout << "\n";
        // for(auto x: v) {
        //     cout << x << " ";
        // } cout << "\n";
        // auto it = s.begin();
        // std::advance(it, k);
        // cout << *(it) << " ";
        cout << v[k] << " ";
    }
}