#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, mF, mS, mC, last, corr;
    cin >> n;
    while(n--) {
        cin >> mF >> mS >> mC >> last >> corr;
        if(mF<mC && last<=mC && mS<=mC && (mF+mS)%mC==last) {
            cout << "OK\n";
            continue;
        }
        if(corr==0) {
            cout << "WRONG" << "\n";
        } else if(corr==1) {
            int ans = (last-mS+mC)%mC;
            cout << "WRONG " << ans << "\n";
        } else if(corr==2) {
            int ans = (last-mF+mC)%mC;
            cout << "WRONG " << ans << "\n";
        } else if(corr==3) {
            int ans = last > mF ? last+1 : mS+(mF-last);
            cout << "WRONG " << ans << "\n";
        } else if(corr==4) {
            int ans = (mF+mS)%mC;
            cout << "WRONG " << ans << "\n";
        }
    }
}