#include<bits/stdc++.h>
using namespace std;

int main() {
    deque<int> dq;
    map<pair<string,int> , vector<pair<string,string> > > mp;

    for(int i=0;i<10;i++)
        dq.push_back(i);
    dq.pop_back();
    dq.push_front(111);
    while(!dq.empty()) {
        cout << dq.front() << endl;
        dq.pop_front();
    }
}