#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    vector<int> v1,v2,ans;

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        v1.push_back(a);
    }

    for(int i=0;i<m;i++) {
        int a;
        cin >> a;
        v2.push_back(a);
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    while(it1!=v1.end() && it2!=v2.end()) {
        if(*it1 == *it2) {
            ans.push_back(*it1);
            it1++;
            it2++;
        } else if(*it1 > *it2) {
            it2++;
        } else if(*it2> *it1) {
            it1++;
        }
    }

    auto it = ans.begin();
    while(it != ans.end()){

        if(it != ans.begin() && *it == *(it-1)){
                it++;
                continue;
        }

        cout << *it << " ";
        it++;
    }

//    for(auto x : ans) {
//       cout << x << " ";
//    }

    return 0;
}
