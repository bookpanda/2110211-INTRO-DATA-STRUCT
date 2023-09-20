#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, mFront, mSize, mCap, last, corr;

    cin >> n;
    while(n--) {
        cin >> mFront >> mSize >> mCap >> last >> corr;
        if(mFront < mCap && last < mCap && mSize <= mCap && (mFront+mSize) % mCap == last){
            cout << "OK\n";
            continue;
        }
        if(!corr) {
            cout << "WRONG\n";
            continue;
        }

        int ans;
        if(corr == 1) {
            ans = (last-mSize+mCap) % mCap;
        } else if(corr == 2) {
            ans = (last-mFront+mCap) % mCap;
        } else if(corr == 3) {
            ans = mFront<last ? last+1 : mSize + mFront-last;
        } else if(corr == 4) {
            ans = (mFront+mSize) % mCap;
        }
        cout << "WRONG " << ans << "\n";
    }
  }