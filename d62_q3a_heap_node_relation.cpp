#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;

    cin >> n >> m;
    while(m--) {
        int a,b;
        cin >> a >> b;
        if(a == b) {
            cout << "a and b are the same node\n";
            continue;
        }
        if(a>b) {
            while(b<a) {
                a = (a-1)/2;
            }
            if(b == a) {
                cout << "b is an ancestor of a\n";
            } else {
                cout << "a and b are not related\n";
            }
        } else {
            while(a<b) {
                b = (b-1)/2;
            }
            if(b == a) {
                cout << "a is an ancestor of b\n";
            } else {
                cout << "a and b are not related\n";
            }
        }
    }
}