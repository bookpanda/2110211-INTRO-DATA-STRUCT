#include<bits/stdc++.h>
using namespace std;

int b[1000010];
int main() {
    int n,k,v;

    cin >> n >> k >> v;
    for(int i=0;i<=n;i++) {
        if(i == k) {
            b[i] = v;
            continue;
        }
        cin >> b[i];
    }

    // for(int i=0;i<=n;i++) {
    //     cout << i << " ";
    // } cout << "\n";
    // for(int i=0;i<=n;i++) {
    //     cout << b[i] << " ";
    // } cout << "\n";

    int pl=k, pr=k;
    int sl=k, sr=k;
    while(pl>=0 && pr<=n) {
        int cou=1;
        if(pl!=pr) cou++;
        while(pl-1>=0 && b[pl] == b[pl-1]) {
            pl--;
            cou++;
        }
        while(pr+1<=n && b[pr] == b[pr+1]) {
            pr++;
            cou++;
        }
        // cout << "pl = " << pl << "  pr = " << pr << "   cou = " << cou << "\n";
        if(b[pl] == b[pr] && cou>2) {
            sl=pl-1;
            sr=pr+1;
            pl--;
            pr++;
        } else {
            break;
        }
    }

    // cout << "FINAL sl = " << sl << "  sr = " << sr << "\n";
    for(int i=0;i<=n;i++) {
        if(i>sl && i<sr) continue;
        cout << b[i] << " ";
    }
}