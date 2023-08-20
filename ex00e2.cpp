#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m,r;
    int table[112][112];
    cin >> n >> m;
    cin >> r;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> table[i][j];
        }
    }
    for(int i=0; i<r; i++) {
        int r1,r2,c1,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--;
        c1--;
        r2--;
        c2--;

        if(r1>r2 || c1>c2) {
            cout << "INVALID" << endl;
            continue;
        }
        if( r2 < 0 || r1 > n-1 || c2 < 0 || c1 > m-1) {
            cout << "OUTSIDE" << endl;
            continue;
        }

        r1 = max(0, r1);
        r2 = min(n-1, r2);
        c1 = max(0, c1);
        c2 = min(m-1, c2);

        int ans = -INT_MAX;
        for(int i=r1;i<=r2;i++) {
            for(int j=c1;j<=c2;j++) {
                ans = max(ans, table[i][j]);
            }
        }
        cout << ans << endl;

//        cout << r1 << c1 << r2 << c2 << endl;

    }
    return 0;
}
