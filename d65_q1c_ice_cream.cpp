#include<bits/stdc++.h>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(0);
    int n,m,r;
    int rate[100010], date[100010];
    vector<pair<int,int> > v;
    vector<int> vs, vd;
    int sum = 0;
    int prevdate = 0;

    cin >> n >> m >> rate[0];
    r = rate[0];

    v.push_back(make_pair(0,r));
    for(int i=1;i<=n;i++) {
        int a,s;
        cin >> a >> s;
        v.push_back(make_pair(a,s));
    }
    sort(v.begin(), v.end());
    for(int i=1;i<=n;i++) {
        date[i] = v[i].first;
        rate[i] = v[i].second;
    }

    vs.push_back(r);
    vd.push_back(0);
    for(int i=1;i<=n;i++) {
        sum += r * (date[i] - prevdate);
        prevdate = date[i];
        r = rate[i];
        vs.push_back(sum);
        vd.push_back(prevdate-1);
    }

    // cout << "\n VS, VD: \n";
    // for(int i=0;i<=n;i++) {
    //     cout << vs[i] << " " << vd[i] << "\n";
    // }
    // cout << "========== \n";

    for(int i=0;i<m;i++) {
        int price, scamday;
        cin >> price >> scamday;
        
        auto it = lower_bound(vs.begin(), vs.end(), price);
        if(it == vs.begin()) {
            // cout << "first day\n";
            cout << "0 ";
        } else {
            //check for scam first
            int idx = it - vs.begin();
            // cout << "idx = " << idx << " rate = " << rate[idx-1] << endl;
            int day = vd[idx-1];
            int need = price - vs[idx-1];
            // cout << "need = " << need << endl;
            int a = need / rate[idx-1];
            int b = need % rate[idx-1];
            if(b > 0) a++;
            day += a;
            // cout << "day = " << day << endl;

            if(day > scamday) {
                // cout << "scam\n";
                //find cumulative amount of scam day
                auto dit = lower_bound(vd.begin(), vd.end(), scamday);
                int scam = 0;
                int didx = dit - vd.begin();
                if(dit == vd.end()) {
                    scam += vs[n];
                    // cout << "scam += " << vs[n] << endl;
                } else {
                    scam += vs[didx-1];
                    // cout << "scam += " << vs[didx-1] << endl;
                }
                scam += rate[didx-1] * (scamday-vd[didx-1]);
                // cout << "scam += " << rate[didx-1] << " * " << (scamday-vd[didx-1]) << "aka " << rate[didx-1] * (scamday-vd[didx-1]) << " = " <<  scam << endl;
                int price2 = price + scam;
                // cout << "price2 = " << price << " + " << scam << " = " <<  price2 << endl;
                auto it2 = lower_bound(vs.begin(), vs.end(), price2);
                // cout << "*it2 = " << *it2 << endl;
                if(it2 == vs.begin()) {
                    cout << "0 ";
                } else {
                    int idx2 = it2 - vs.begin();
                    // cout << "idx2 = " << idx2 << " rate = " << rate[idx2-1] << endl;
                    int day = vd[idx2-1];
                    int need = price2 - vs[idx2-1];
                    //  cout << "need = " << need << endl;
                    int a = need / rate[idx2-1];
                    int b = need % rate[idx2-1];
                    if(b > 0) a++;
                    day += a;
                    cout << day << " ";
                }

            } else {
                // cout << "before scam\n";
                cout << day << " ";
            }
        }

        // cout <<  "\n\n\n\n";
    }
}