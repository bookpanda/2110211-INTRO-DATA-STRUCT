#include<bits/stdc++.h>

using namespace std;

int main() {
    int n,m;
    int target[100112], command[100112];
    vector<int> v;
    queue<int> pa, pb, app;

    cin >> n >> m;

    for(int i=0;i<m;i++) {
        cin >> target[i];
    }

    int sum = 0;
    for(int i=0;i<n;i++) {
        int a,b;
        cin >> command[i];
        if(command[i] == 1) {
            cin >> a >> b;
            app.push(a);
            if(a == 1)
                pa.push(b);
            else if(a == 2)
                pb.push(b);
        } else if(command[i] == 2) {
            if(pa.empty() && !pb.empty()) {
                v.push_back(sum + pb.front());
                sum += pb.front();
                pb.pop();
            } else if(!pa.empty() && pb.empty()) {
                v.push_back(sum + pa.front());
                sum += pa.front();
                pa.pop();
            } else if(pa.front() <= pb.front()) {
                v.push_back(sum + pa.front());
                sum += pa.front();
                pa.pop();
            } else if(pa.front() > pb.front()) {
                v.push_back(sum + pb.front());
                sum += pb.front();
                pb.pop();
            }
        }
    }

    for(int i=0;i<m;i++) {
        auto it = lower_bound(v.begin(), v.end(), target[i]);
        if(it == v.end()) {
            cout << "-1\n";
        } else {
            int ans = it - v.begin();
//            cout << "price : " << *it << " index=" << ans << endl;
            cout << ans + 1  << "\n";
        }
    }
}
