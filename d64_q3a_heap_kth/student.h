#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  //can include anything
  if(k==1) return mData[0];
  if(k==2) {
    return mLess(mData[1], mData[2]) ? mData[2] : mData[1];
  }
  std::vector<T> v;
  for(int i=1;i<7;i++) {
    if(i < mSize) v.push_back(mData[i]);
  }
  sort(v.begin(), v.end(), mLess);
  return v[v.size()-2];
}

#endif
