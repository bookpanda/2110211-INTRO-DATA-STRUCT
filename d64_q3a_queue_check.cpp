#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    
    cin >> n;
    while(n--) {
        int mF, mS, mC, last, corr;
        cin >> mF >> mS >> mC >> last >> corr;
        bool _mF = mF != (last - mS + mC) % mC;
        bool _mS = mS != (last - mF + mC) % mC;
        bool _last = last != (mF + mS + mC) % mC;
        if(mF<mC && last<mC && mS<=mC && (mF+mS)%mC == last) {
            cout << "OK\n";
            continue;
        }
        if(corr==0) {
            cout << "WRONG\n";
            continue;
        } 
        int ans;
        if(corr==1) {
            ans = (last - mS + mC) % mC;
        } else if(corr==2) {
            ans = (last - mF + mC) % mC;
        } else if(corr==3) {
            ans = mF<last ? last+1 : mS+mF-last;
        } else if(corr==4) {
           ans = (mF + mS) % mC;
        }
        cout << "WRONG " << ans << "\n";
    }
}