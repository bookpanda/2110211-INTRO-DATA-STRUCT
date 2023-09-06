#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    int seat[1000112];
    priority_queue<pair<int, int> > pq;

    cin >> n >> m;

    for(int i=0;i<n;i++) {
        cin >> seat[i];
    }

    int cou = 0;
    for(int i=0;i<n;i++) {
        cout << "0\n";
        pq.push(make_pair(-1*(0+seat[i]), seat[i]));
        cou++;
        if(cou == m) break;
    }

    for(int i=n;i<m;i++) {
        pair<int,int> top = pq.top();
        int time = top.first;
        int st = top.second;
        pq.pop();
        pq.push(make_pair(time - st, st));
        cout << -1*time << "\n";
    }
}