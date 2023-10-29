#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, mF, mS, mC, last, corr;

    cin >> n;
    while(n--) {
        cin >> mF >> mS >> mC >> last >> corr;
        if(mF < mC && last <= mC && mS <= mC && (mF+mS)%mC == last) {
            cout << "OK\n";
            continue;
        }
        if(corr == 0) {
            cout << "WRONG\n";
        } else if(corr == 1) {
            cout << "WRONG " << (last-mS+mC)%mC << "\n";
        } else if(corr == 2) {
            cout << "WRONG " << (last-mF+mC)%mC << "\n";
        } else if(corr == 3) {
            int ans = last <= mF ? mF-last+mS : last+1;
            cout << "WRONG " << ans << "\n";
        } else if(corr == 4) {
            cout << "WRONG " << (mF+mS)%mC << "\n";
        }
    }
}