#include <iostream>
#include <vector>
using namespace std;
void remove_even(vector<int> &v,int a,int b) {
 //write your code only in this function
 if(a%2 != 0) a++;
 if(b%2 != 0) b--;
// cout << a << " " << b << endl;

 for(int i=a;i<=b;i+=2) {
//        cout << i << " " << a << " " << b << endl;
//    if(i % 2 == 0) {
//        cout << "remove" << endl;
        v.erase(v.begin() + i);
//        cout << "remain: " << v.size();
//          for (auto &x : v) {
//         cout << x << " ";
//         }
//         cout << endl;
        i--;
        b--;
//        b--;
//    }
 }
//    v.erase(remove_if(
//    v.begin(), v.end(),
//    [](const int& x) {
//        return xs > 10; // put your condition here
//    }), v.end());
 return;

}
int main() {
 //read input
 int n,a,b;
 cin >> n;
 vector<int> v;
 for (int i = 0;i < n;i++) {
 int c;
 cin >> c;
 v.push_back(c);
 }
 cin >> a >> b;
 //call function
 remove_even(v,a,b);
 //display content of the vector
 for (auto &x : v) {
 cout << x << " ";
 }
 cout << endl;
}
