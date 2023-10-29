#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n,k;
    int lvl=0;
    long long idx=0;

    cin >> n >> k;
    if(k==1) {
        cout << n-1 << "\n";
        return 0;
    }
    while(idx < n) {
        idx = (k*idx)+1;
        if(idx<n) lvl++;
    }
    cout << lvl << "\n";
}