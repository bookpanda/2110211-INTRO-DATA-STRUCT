#include <vector>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> Union(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    set<T> s;

    for(auto x: A){
        s.insert(x);
        v.push_back(x);
    }
    for(auto x: B){
        if(s.find(x) == s.end()) {
            s.insert(x);
            v.push_back(x);
        }
    }

    return v;
}

template <typename T>
vector<T> Intersect(const vector<T>& A, const vector<T>& B) {
    vector<T> v;
    map<T,int> mp;
    set<T> s;
    // vector<T> temp;
    priority_queue<pair<int,T> > pq;
    int idx=0;
     for(auto x: A){
        if(s.find(x) == s.end())
        {
            s.insert(x);   
            mp[x] = idx;
            idx++;
        }
        // v.push_back(x);
    }
    for(auto x: B){
        if(s.find(x) != s.end()) {
            // s.insert(x);
            // v.push_back(x);
            pq.push({-1* mp[x], x});
        }
    }
    while(!pq.empty()){
        v.push_back(pq.top().second);
        pq.pop();
    }
    return v;
}
