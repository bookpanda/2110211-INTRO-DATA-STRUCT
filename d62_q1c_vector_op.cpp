#include<bits/stdc++.h>

using namespace std;

bool desc(int a, int b) {
    return a > b;
}

int main() {
    int q;
    vector<int> v;
    cin >> q;

    for(int ia=0;ia<q;ia++) {
        string cm;
        int n;
        cin >> cm;

        if(cm == "pb") {
            cin >> n;
            v.push_back(n);
        }
        else if(cm == "sa"){
            sort(v.begin(), v.end());
        } else if(cm == "sd") {
            sort(v.begin(), v.end(), desc);
        } else if(cm == "r") {
            reverse(v.begin(), v.end());
        } else if(cm == "d") {
            cin >> n;
            v.erase(v.begin() + n);
        }

    }
    for(auto &x:v){
        cout << x << " ";
    }

    return 0;
}
