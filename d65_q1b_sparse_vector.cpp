#include <iostream>
#include <vector>
#include <map>
using namespace std;
void insert_into_sv(map<int,int> &v, int pos, int value) {
 //your code here
    // cout << "insert " << pos << " " << value << endl;
    auto it = v.end();
    if(v.size() == 0) {
        it = v.begin();
        v.insert(it, make_pair(pos, value));
        return;
    } else it--;
    // cout << "it points to (" << it->first << ", " << it->second << ")\n" ;
    while(it->first >= pos) {
        // cout << "it points to (" << it->first << ", " << it->second << ")\n" ;
        v[it->first + 1] = it->second;
        // cout << "v[" << it->first + 1 << "] = " << it->second << endl;
        // cout << "it points to (" << it->first << ", " << it->second << ")\n" ;
        it = v.erase(it);
        // cout << "it points to (" << it->first << ", " << it->second << ")\n" ;
        if(it == v.begin()) break;
        it--;
    }
    v[pos] = value;
    // v.insert(it, make_pair(pos, value));
}
int main() {
 ios_base::sync_with_stdio(false);cin.tie(0);
 int n;
 map<int,int> v;
 cin >> n;
 for (int i = 0;i < n;i++) {
 int a,b;
 cin >> a >> b;
 insert_into_sv(v,a,b);
 }
 cout << v.size() << "\n";
 for (auto &x : v) {
 cout << x.first << ": " << x.second << "\n";
 }
}
