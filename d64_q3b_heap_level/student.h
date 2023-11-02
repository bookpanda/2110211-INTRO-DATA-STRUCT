#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  //write your code here
  //can include anything
  std::vector<T> v;
  int sz=1;
  for(int i=0;i<k;i++) {
    sz*=2;
  }
  int fidx = sz-1;
  for(int i=0;i<sz;i++) {
    if(i+fidx < mSize)
    v.push_back(mData[i+fidx]);
  }
  sort(v.begin(), v.end(), mLess);
  std::vector<T> ans(v.size());
  int idx=0;
  for(int i=v.size()-1;i>=0;i--) ans[idx++] = v[i];
  return ans;
}

#endif

