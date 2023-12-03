#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,k;

    cin >> n;
    while(n--) {
        cin >> m >> k;
        vector<int> v(m);
        for(int i=0;i<m;i++) {
            cin >> v[i];
        }
        bool flag = false;
        for(int i=m-1;i>=0;i--) {
            if((i-1)/k >=0 && v[i] > v[(i-1)/k]) {
                cout << "false\n";
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout << "true\n";
        }
    }
}