#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    map<string,string> father;

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        string f,s;
        cin >> f >> s;
        father[s] = f;
    }

    for(int i=0;i<m;i++) {
        string a,b;
        cin >> a >> b;
        if(a != b && father[father[a]]!="" && father[father[a]] == father[father[b]] && father[father[b]]!="") {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }


    return 0;
}
