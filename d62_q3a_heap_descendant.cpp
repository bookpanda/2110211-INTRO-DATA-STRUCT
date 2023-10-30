#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,a;
    cin >> n >> a;
    queue<int> q, ans;
    q.push(a);
    while(!q.empty()){
        // cout << q.front() << " ";
        ans.push(q.front());
        if((q.front()*2)+1 < n) q.push((q.front()*2)+1);
        if((q.front()*2)+2 < n) q.push((q.front()*2)+2);
        q.pop();
    }
    cout << ans.size() << "\n";
    while(!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }

}