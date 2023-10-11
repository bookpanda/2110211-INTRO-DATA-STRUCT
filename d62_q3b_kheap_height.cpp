#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n,k;

    cin >> n >> k;
    if(k ==1) {
        cout << n-1 << "\n";
    } else {
        int cou = 0;
        long long a = 1;
        while(n>0) {
            n -= a;
            a *= k;
            cou++;
        }
        cout << cou-1 << "\n";
    }
}