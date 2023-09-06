#include<bits/stdc++.h>

using namespace std;

priority_queue<pair<pair<int,int>,int> > pq[1000112];
map<int,int> ma[1000112];
vector<int> ans[1000112];
int main() {
    int n,m,a;
    int stock[1000112];
    // priority_queue<pair<pair<int,int>, pair<int,int> > > pq;

    cin >> n >> m >> a;

    for(int i=1;i<=n;i++) {
        cin >> stock[i];
    }

    for(int i=0;i<a;i++) {
        int u, I, v;
        string comm;
        cin >> comm;
        if(comm == "B") {
            cin >> u >> I >> v;
            pq[I].push(make_pair(make_pair(i,v),u));
            // pq.push(make_pair(make_pair(i,v), make_pair(u,I)));
        } else if(comm == "W") {
            cin >> u >> I;
            pq[I].push(make_pair(make_pair(i,-1),u));
            // pq.push(make_pair(make_pair(i,-1), make_pair(u,I)));
        }
    }

    for(int i=1;i<=n;i++) {
        // cout << "ITEM " << i << endl;
        while(!pq[i].empty()) {
            int t, val, u, item;
            pair<pair<int,int>, int > top = pq[i].top();
            pq[i].pop();
            // t = top.first.first; latest first
            val = top.first.second;
            u = top.second;

            // cout << "val: " << val << "   user: " << u << endl;

            if(ma[i].find(u) == ma[i].end()) { //no history of user
                ma[i][u] = val;
                // cout << "no hist, ma[i][" << u << "] = " << val << endl;
            } else {
                if(ma[i][u] == -1 || val == -1) continue; //already withdrawn or withdraw of the past
            }
        }
    }

    for(int i=1;i<=n;i++) {
        //check stock, reduce priority to size of stock
        priority_queue<pair<int,int> > win; 
        for(auto x: ma[i]) {   
            // cout << "x.second = " << x.second << endl; 
            if(x.second != -1)
            win.push(make_pair(x.second, x.first));
        }
        int cou = 0;
        while(!win.empty()) {
            pair<int,int> top = win.top();
            win.pop();
            int user = top.second;
            ans[user].push_back(i);
            // cout << "ans[user " << user << "].push(item " << i << ")\n";
            cou++;
            if(cou == stock[i]) break;
        }
    }

    for(int i=1;i<=m;i++) {
        int cou = 0;
        for(auto x: ans[i]) {
            cout << x << " ";
            cou++;
        }
        if(cou == 0) cout << "NONE";
        cout << "\n";
    }
}