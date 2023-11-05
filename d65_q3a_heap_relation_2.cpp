#include <iostream>
#include <vector>
using namespace std;
int relation(long long k, long long a, long long b) {
    int lvla=0,lvlb=0;
    if(a < b) swap(a,b);
    a = (a-1)/k;
    lvla++;
    if(a == b) return 1;
    while(a>0) {
        a = (a-1)/k;
        lvla++;
        if(a==b) return 2;
    }
    while(b>0) {
        b = (b-1)/k;
        lvlb++;
    }
    if(lvla == lvlb) return 4;
    return 3;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    long long S,a,b;
    cin >> n;
    while (n--) {
        cin >> S >> a >> b;
        cout << relation(S,a,b) << " ";
    }
    cout << endl;
}