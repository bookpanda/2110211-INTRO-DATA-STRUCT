#include<bits/stdc++.h>

using namespace std;

int main() {
    cout << std::fixed << std::setprecision(2);

    int n;
    vector<pair<string, int>> vc;
    vector<pair<string, int>> vp;

    cin >> n;

    for(int i=0;i<n;i++) {
        string p,c;
        int score;

        cin >> c >> p >> score;
        vc.push_back({c, score});
        vp.push_back({p, score});
    }

    sort(vc.begin(), vc.end());
    sort(vp.begin(), vp.end());

    int cou=0;
    int sum=0;
    for(int i=0;i<n;i++) {
        if(i!=0 && vc[i].first != vc[i-1].first) {
            cout << vc[i-1].first << " " << (sum+0.00)/cou << "\n";
            cou = 0;
            sum = 0;
        }
        cou++;
        sum += vc[i].second;

    }
    cout << vc[n-1].first << " " << (sum+0.00)/cou << "\n";

    cou=0;
    sum=0;
    for(int i=0;i<n;i++) {
        if(i!=0 && vp[i].first != vp[i-1].first) {
            cout << vp[i-1].first << " " << (sum+0.00)/cou << "\n";
            cou = 0;
            sum = 0;
        }
        cou++;
        sum += vp[i].second;

    }
    cout << vp[n-1].first << " " << (sum+0.00)/cou << "\n";

    return 0;
}
