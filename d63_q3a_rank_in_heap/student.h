#ifndef __STUDENT_H_
#define __STUDENT_H_
#include<bits/stdc++.h>
using namespace std;

static bool init = false;
static vector<int> ranks;

using namespace std;

template <typename T,typename Comp>
size_t CP::priority_queue<T,Comp>::get_rank(size_t pos) const {
  //write your code here
  if(!init) {
    map<int, int> mp;
    std::vector<pair<T, int> > v(mSize);
    for(int i=0;i<mSize;i++) {
      v[i] = {mData[i], i};
    }
    sort(v.begin(), v.end());
    if(mLess(T(0), T(1))) reverse(v.begin(), v.end());
    ranks.resize(mSize);
    int j=0;
    for(int i=0;i<mSize;i++) {
      if(v[j].first != v[i].first) j = i;
      ranks[v[i].second] = j;
    }
    init = true;
  }
  return ranks[pos];
}

#endif
