#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    map<string, int> m;

    cin >> n;
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        m[s]++;
    }

    int ans=0;
    string s;
    for(auto it: m) {
        if(ans < it.second) {
            ans = it.second;
            s = it.first;
        } else if(ans == it.second && s < it.first) {
            ans = it.second;
            s = it.first;
        }
//        cout << it.first << " " << it.second << endl;
    }

    cout << s << " " << ans << endl;

//    auto it = m.rbegin();
//    cout << it->first << " " << it->second << endl;
}
