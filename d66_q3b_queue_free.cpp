#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long mS=0, mC=1;

    cin >> n;
    while(n--) {
        int a, k;
        cin >> a >> k;
        if(a == 0) {
            mS += k;
            while(mC < mS) {
                mC *= 2;
            }
        } else if(a == 1) {
            mS = mS-k;
            if(mS < 0) mS = 0;
        }
    }
    cout << mC - mS << "\n";
}