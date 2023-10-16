#include <iostream>
#include <vector>
using namespace std;

int relation(long long S, long long a, long long b) {
    long long lvla=0, lvlb=0;
    long long ta=a, tb=b;
    if(a == b) return 4;
    if(a == (b-1)/S || b == (a-1)/S) return 1;
    while(ta>0) {
        // std::cout << "ta = " << ta << "\n";
        if(ta == b) {
            return 2;
        }
        ta = (ta-1)/S;
        lvla++;
    }
    if(ta == b) return 2;
    while(tb>0) {
        // std::cout << "tb = " << tb << "\n";
        if(tb == a) {
            return 2;
        }
        tb = (tb-1)/S;
        lvlb++;
    }
    if(tb == a) return 2;
    if(lvla != lvlb) return 3;
    return 4;
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