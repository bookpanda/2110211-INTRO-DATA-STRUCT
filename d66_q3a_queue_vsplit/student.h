#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <algorithm>
#include <vector>
#include "queue.h"

template <typename T>
void CP::queue<T>::v_split(std::vector<std::queue<T>> &output, size_t k) const
{
  // your code here
  int sz = mSize/k;
  int quota = mSize - k*sz;
  int idx=0;
  for(int i=0;i<k;i++) {
    output.push_back({});
    int qs = sz;
    if(quota) {
      quota--;
      qs++;
    }
    for(int j=0;j<qs;j++) {
      output.back().push(mData[(mFront + idx) % mCap]);
      idx++;
    }
  }
}

#endif
