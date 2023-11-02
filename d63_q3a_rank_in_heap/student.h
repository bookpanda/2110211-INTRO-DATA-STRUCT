#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<bits/stdc++.h>
using namespace std;

static bool init = false;
static map<int, int> mp;

using namespace std;

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
  //write your code here
  if(!init) {
    std::vector<std::pair<int,int> > v;
    for(int i=0;i<mSize;i++) {
      v.push_back({mData[i], -i});
    } 
    sort(v.begin(), v.end());
    if(mLess(T(0), T(1))) reverse(v.begin(), v.end());
    int prev=-1;
    int mini=0;
    for(int i=0;i<v.size();i++) {
      // cout << "(" << v[i].first << ", " << v[i].second << ")\n";
      if(prev == v[i].first) {
        mp[-v[i].second] = min(mini, i);
      } else {
        mp[-v[i].second] = i;
        mini = i;
      }

      prev = v[i].first;
    }
    // for(auto x: mp) {
    //   cout << x.first << ", " << x.second << "\n";
    // }
    init = true;
  }
  return mp[pos];
  
}

#endif
