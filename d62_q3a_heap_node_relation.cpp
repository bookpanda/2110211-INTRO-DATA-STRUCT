#include<bits/stdc++.h>
using namespace std;

map<int,set<int> > c;
int main() {
    int n,m;

    cin >> n >> m;
    for(int i=0;i<m;i++) {
        int a, b;
        cin >> a >> b;
        if(a == b) {
            cout << "a and b are the same node\n";
        } else if(a < b) {
            while(b > a) {
                b = (b-1)/2;
            }
            if(b == a) {
                cout << "a is an ancestor of b\n";
            } else cout << "a and b are not related\n";
        } else if(a > b) {
            while(a > b) {
                a = (a-1)/2;
            }
            if(b == a) {
                cout << "b is an ancestor of a\n";
            } else cout << "a and b are not related\n";
        }
    }
}