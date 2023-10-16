#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  //write your code here
  //can include anything
  int st = 1;
  while(k--) st *= 2;
  int sz = st;
  st -= 1;
  if(st > mSize) return {};
  std::vector<T> r, ans;
  for(int i=0;i<sz;i++) {
    if(i+st >= mSize) break;
    r.push_back(mData[i+st]);
  }
  sort(r.begin(), r.end(), mLess);
  for(int i=r.size()-1;i>=0;i--) ans.push_back(r[i]);
  return ans;
}

#endif

