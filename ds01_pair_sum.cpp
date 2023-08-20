#include<bits/stdc++.h>

using namespace std;

int lookup[2000112];
int main() {
    int n,m;
    vector<int> v;
//    map<int,int> lookup;

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            lookup[v[i] + v[j]] = 1;
        }
    }

    for(int i=0;i<m;i++) {
        int sum;
        cin >> sum;
        if(lookup[sum] == 1)
        cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
