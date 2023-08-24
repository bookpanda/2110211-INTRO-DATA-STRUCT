#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    map<string, int> m;

    cin >> n;
    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        if(m.find(s) == m.end()) {
            m[s] = 0;
        }
        m[s]++;
    }

    for(auto x:m) {
        if(x.second > 1) {
            cout << x.first << " " << x.second << endl;
        }
    }
}
