#include<bits/stdc++.h>
using namespace std;

map<int,int> t;
int main() {
    int n,m;

    cin >> n >> m;
    while(n--) {
        int a;
        cin >> a;
        t[a] += 1;
    }
    while(m--) {
        int amou;
        cin >> amou;
        while(amou--) {
            int a;
            cin >> a;
        }
    }
    for(auto x: t){
        cout << x.first << " : " << x.second << endl;
    }
}