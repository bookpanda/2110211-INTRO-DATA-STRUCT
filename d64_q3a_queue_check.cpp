#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;
    while(n--) {
        int mF, mS, mC, last, corr;
        cin >> mF >> mS >> mC >> last >> corr;
        if(mS<=mC && mF<mC && last<=mC && (mF+mS)%mC==last) {
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
            if(last <= mF) cout << "WRONG " << (mS + (mF-last)) << "\n";
            else cout << "WRONG " << (last+1) << "\n";
        } else if(corr == 4) {
            cout << "WRONG " << (mF+mS)%mC << "\n";
        }
    }
}