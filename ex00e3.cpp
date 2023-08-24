#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    vector<int> v;
    cin >> n;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());

    int flag = 0;
    for(int i=0;i<n;i++) {
        if(i+1 != v[i]) {
            cout << "NO" << endl;
            flag = 1;
            break;
        }
    }
    if(flag==0)
        cout << "YES" << endl;

    return 0;
}
