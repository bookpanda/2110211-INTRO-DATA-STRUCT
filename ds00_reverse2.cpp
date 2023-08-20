#include <iostream>
#include <vector>
using namespace std;
void reverse(vector<int> &v,vector<int>::iterator a,vector<int>::iterator b) {
//write your code only in this function
    auto it1 = a;
    auto it2 = b - 1;

    int cou = 1;
    while(it1 < it2) {
        swap(*it1, *it2);

        it1 = a+cou;
        it2 = b-cou-1;
        cou++;
    }
}
int main() {
//read input
    int n,a,b;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        v.push_back(c);
    }
    cin >> a >> b;
//call function
    reverse(v,v.begin()+a,v.begin()+b+1);
//display content of the vector
    for(auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}
