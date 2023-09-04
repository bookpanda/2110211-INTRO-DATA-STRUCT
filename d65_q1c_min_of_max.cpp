#include<bits/stdc++.h>

using namespace std;

set<int> dp[500010];
int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m;
    int power[500010], type[500010];
    multiset<int> ans;

    cin >> n >> m;
    for(int i=0;i<m;i++)
        ans.insert(1);
    for(int i=0;i<n;i++) {
        dp[i].insert(-1);
    }

    for(int i=0;i<n;i++) {
        cin >> power[i];
    }

    for(int i=0;i<n;i++) {
        cin >> type[i];
    }
    // for(auto i: ans){
    //         cout << i << " "; 
    //     }
    //     cout << "\n";


    for(int i=0;i<n;i++) {
        auto itr = ans.find(-1* (*dp[type[i]].begin()));
        if(itr != ans.end()) {
            ans.erase(itr);
        }
        // cout << "erase  " << -1* (*dp[type[i]].begin()) << "\n";
        dp[type[i]].insert(-1*power[i]);
        set<int>::iterator it = dp[type[i]].begin();

        // cout << "insert " << -1*(*it) << "\n";
        ans.insert(-1* (*it));
        // for(auto i: ans){
        //     cout << i << " "; 
        // }
        // cout << "\n";

        cout << *(ans.begin()) << " ";
    }


}