#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long cap = 1;
    long long sz = 0;


    cin >> n;
    while(n--) {
        int a,k;
        cin >> a >> k;
        if(a == 0) {
            while(cap < sz + k) {
                cap *= 2;
            }
            sz += k;
        } else if(a == 1) {
            sz -= k;
        }
    }
    cout << cap - sz << "\n";
}