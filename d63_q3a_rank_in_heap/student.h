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
    init = true;
    vector<pair<T, int> > v(mSize);
    for(int i=0;i<mSize;i++) {
      v[i] = {mData[i], -i};
    }
    sort(v.begin(), v.end());
    if(mLess(T(0), T(1))) reverse(v.begin(), v.end());
    int prev=-1;
    int mini=0;
    for(int i=0;i<v.size();i++) {
      if(prev == v[i].first) {
        mp[-v[i].second] = min(mini, i);
      } else {
        mp[-v[i].second] = i;
        mini = i;
      }
      prev = v[i].first;
      // cout << x.first << " , " << x.second << "\n";
      // if(mp.find(-v[i].second) == mp.end()) {
      //   mp[-v[i].second] = mSize - i-1;
      // } else if(mSize - i-1 < mp[-v[i].second])
      // mp[-v[i].second] = mSize - i-1;
    }
  }
  return mp[pos];
}

#endif
