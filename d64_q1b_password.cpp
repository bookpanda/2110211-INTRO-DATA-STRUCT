#include<bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,l;
    int k[100];
    map<string,string> mp;

    cin >> n >> m >> l;

    for(int i=0;i<l;i++) {
        cin >> k[i];
        k[i] %= 26;
    }

    for(int i=0;i<n;i++) {
        string s;
        cin >> s;
        for(int j=0;j<l;j++) {
            s[j] -= k[j];
            if(s[j] < 'a')
                s[j] += 26;
        }
        mp[s] = 1;
    }

//    for(auto x: mp) {
//        cout << "ass " << x.first << endl;
//    }

    for(int i=0;i<m;i++) {
        string s;
        cin >> s;
//        for(int j=0;j<l;j++) {
//            s[j] += k[j];
//            if(s[j] > 'z')
//                s[j] -= 26;
//        }
        if(mp.find(s)!=mp.end()) {
            cout << "Match\n" ;
        } else {
            cout << "Unknown\n";
        }

    }
}
