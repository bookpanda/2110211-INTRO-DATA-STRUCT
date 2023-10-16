#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <algorithm>
#include <vector>
#include "priority_queue.h"

template <typename T,typename Comp >
T CP::priority_queue<T,Comp>::get_kth(size_t k) const {
  //write your code here
  //can include anything
  if(k == 1) return mData[0];
  if(k == 2) {
    T idx1 = mData[1];
    T idx2 = mData[2];
    return mLess(idx1, idx2) ? idx2 : idx1;
  }
    std::vector<T> v;
    int cou=0;
    for(int i=1;i<mSize;i++) {
      v.push_back(mData[i]);
      cou++;
      if(cou == 6) break;
    }
    sort(v.begin(), v.end(), mLess);
    return *(v.rbegin()+1);
  
}

#endif
