#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,a;
    queue<int> q, ans;

    cin >> n >> a;
    q.push(a);
    int cou = 0;
    while(!q.empty()) {
        cou++;
        ans.push(q.front());
        if((q.front()*2)+1 < n)
            q.push((q.front()*2)+1);
        if((q.front()*2)+2 < n)
            q.push((q.front()*2)+2);
        q.pop();
    }

    cout << cou << "\n";
    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
}