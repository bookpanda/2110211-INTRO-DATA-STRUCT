#include<bits/stdc++.h>

using namespace std;

set<pair<string, string> > s;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m;
   
    cin >> n >> m;

    while(n--) {
        string a,b;
        cin >> a >> b;
        s.insert(make_pair(a,b));
    }

    while(m--) {
        int amou;
        vector<pair<string,string> > v;
        bool flag = false;
        cin >> amou;
        while(amou--) {
            string a,b;
            cin >> a >> b;
            if(s.find(make_pair(a,b)) != s.end()) { //found ticket
                v.push_back(make_pair(a,b));
            } else {
                flag = true;
            }
        }
        if(flag) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for(auto x:v){
                s.erase(x);
            }
        }
    }
}