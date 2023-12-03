#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
std::vector<T> CP::priority_queue<T,Comp>::at_level(size_t k) const {
  //write your code here
  //can include anything
  int idx=0;
  for(int i=0;i<k;i++) {
    idx = (idx*2)+1;
  }
  int nextlvl = (idx*2)+1;
  std::vector<T> v;
  while(idx<mSize && idx<nextlvl) {
    v.push_back(mData[idx]);
    idx++;
  }
  sort(v.begin(), v.end(), mLess);
  std::vector<T> ans;
  for(int i=v.size()-1;i>=0;i--) {
    ans.push_back(v[i]);
  }
  return ans;
}

#endif

