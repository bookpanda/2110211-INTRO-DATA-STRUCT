#include<bits/stdc++.h>

using namespace std;

bool desc(int a, int b){
    return a > b;
}

int main() {
    int n,m;
    map<string, int> vote;
    vector<int> v;

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        string name;
        cin >> name;
        vote[name]++;
    }

    for(auto x:vote) {
        v.push_back(x.second);
    }
    sort(v.begin(), v.end(), desc);

    auto it = v.begin() + m - 1;
    if(it >= v.end()) {
        it = v.end()-1;
    }
    while(it >= v.begin() && *it==0){
        it--;
    }

    cout << *it << endl;

    return 0;
}
