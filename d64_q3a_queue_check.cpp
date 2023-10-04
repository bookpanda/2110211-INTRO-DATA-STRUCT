#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int mF, mS, mC, last, corr;

    cin >> n;
    while(n--) {
        cin >> mF >> mS >> mC >> last >> corr;
        if(mF<mC && last<mC && mS<=mC && last == (mF+mS) % mC) {
            cout << "OK\n";
            continue;
        }

        if(corr == 0){
            cout << "WRONG\n";
        } else if(corr == 1) {//mF
            cout << "WRONG " << (last-mS+mC) % mC << "\n";
        } else if(corr == 2) {//mS
            cout << "WRONG " << (last-mF+mC) % mC << "\n";
        } else if(corr == 3) {//mC
            int ans = last > mF ? mS+mF+1 : (mF+mS-last);
            cout << "WRONG " << ans << "\n";
        } else if(corr == 4) {//lasts
            cout << "WRONG " << (mF+mS) % mC << "\n";
        }
    }
}